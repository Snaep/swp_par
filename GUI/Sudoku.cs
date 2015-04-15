using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI {
    class Sudoku {
        //y x
        private System.Drawing.Font fPreSetCell = null;
        private System.Drawing.Font fFilledCell = null;
        private System.Drawing.Brush brFilledCell = null;
        private System.Drawing.Pen pThickLine = null;
        private Cell[][] grid;
        private int N;

        internal Sudoku( int length ) {
            this.grid = new Cell[length][];
            if( this.grid == null ) throw new OutOfMemoryException();

            for(int i = 0; i < length; i++) {
                this.grid[i] = new Cell[length];
                if( this.grid[i] == null ) throw new OutOfMemoryException();
                for( int j = 0; j < length; j++ ) {
                    this.grid[i][j] = new Cell( null, false );
                }
            }

            this.N = (int)Math.Sqrt( length );        
        }

        internal Sudoku( string path ) {
            this.LoadFromFile( path );
            this.N = ( int )Math.Sqrt( this.Length );
        }

        private Sudoku( Cell[][] lgrid ) {
            this.grid = lgrid;
            this.N = ( int )Math.Sqrt( this.Length );
        }

        internal static Sudoku Parse( string p1, char p2 ) {
            Cell[][] lgrid = null;
            int i = 0;

            string[] lines = p1.Split( new string[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries );
            if( lines.Length <= 2 ) return null;

            foreach( string line in lines ) {
                string[] contents = line.Split( p2 );
                Cell[] cells = new Cell[contents.Length];
                for( int j = 0; j < cells.Length; j++ ) {
                    string value = contents[j];
                    if( value == "" ) value = null;
                    cells[j] = new Cell( value, true );
                }
                if( lgrid == null ) lgrid = new Cell[cells.Length][];

                if( cells.Length == lgrid.Length ) lgrid[i++] = cells;
                else return null;
            }

            return new Sudoku( lgrid );
        }

        private void CreateResources() {
            this.pThickLine = new System.Drawing.Pen( System.Drawing.Color.Black, 2 );
            this.fPreSetCell = new System.Drawing.Font( "Consolas", 14, System.Drawing.FontStyle.Bold );
            this.fFilledCell = new System.Drawing.Font( "Consolas", 14, System.Drawing.FontStyle.Regular );
            this.brFilledCell = new System.Drawing.SolidBrush( System.Drawing.Color.DarkBlue );
        }

        internal void SaveToFile( string file ) {
            using( var stream = new System.IO.FileStream( file,System.IO.FileMode.CreateNew ) ) {
                byte[] buff;
                foreach( var row in this.grid ) {
                    foreach( var cell in this.grid ) {
                        buff = Encoding.Default.GetBytes(cell.ToString() + ' ');
                        stream.Write(buff, 0, buff.Length);    
                    }
                    buff = Encoding.Default.GetBytes(Environment.NewLine);
                    stream.Write( buff, 0, buff.Length );
                }        
            }
        }

        internal void LoadFromFile( string file ) {
            Cell[][] lgrid;
            int i = 0;

            using( var reader = new System.IO.StreamReader( file ) ) {
                lgrid = null;
                while(!reader.EndOfStream) {
                    string[] contents = reader.ReadLine().Split( ' ' );
                    Cell[] cells = new Cell[contents.Length];
                    for( int j = 0; j < cells.Length; j++ ) {
                        string value = contents[j];
                        if( value == "" ) value = null;
                        cells[j] = new Cell( value, true );
                    }
                    if( lgrid == null ) lgrid = new Cell[cells.Length][];  
                    
                    if(cells.Length == lgrid.Length) lgrid[i++] = cells;
                }
            }

            this.grid = lgrid;
        }

        internal void ApplyPreset( Sudoku preset ) {
            for( int y = 0; y < this.grid.Length; y++ ) {
                for( int x = 0; x < this.grid.Length; x++ ) {
                    if( preset.grid[y][x] != null ) this.grid[y][x].IsPreset = true;
                }
            }
        }

        internal Cell GetCell( int x, int y ) {
            return this.grid[y][x];
        }     

        internal void SetCell( int x, int y, string content, bool isPreset ) {
            this.grid[y][x] = new Cell( content, isPreset );
        }
        internal void SetCell( int x, int y, Cell value ) {
            this.grid[y][x] = value;
        }

        internal int Length {
            get {
                return this.grid.Length;
            }
        }

        internal System.Drawing.Image ToImage( int boxSize = 30 ) {
            System.Drawing.Image img = new System.Drawing.Bitmap( boxSize * ( this.Length + 2 ), boxSize * ( this.Length + 2 ) );
            System.Drawing.Graphics g = System.Drawing.Graphics.FromImage( img );
            int iGridWidth = boxSize * this.Length;


            if( this.pThickLine == null ) this.CreateResources();

            g.TextRenderingHint = System.Drawing.Text.TextRenderingHint.AntiAlias;

            g.DrawRectangle( this.pThickLine, boxSize, boxSize, iGridWidth, iGridWidth );

            for( int i = boxSize, j = 0; i < iGridWidth + boxSize; i += boxSize, j++ ) {
                if( j % this.N == 0 ) {
                    g.DrawLine( this.pThickLine, i, boxSize, i, iGridWidth + boxSize );
                    g.DrawLine( this.pThickLine, boxSize, i, iGridWidth + boxSize, i );
                } else {
                    g.DrawLine( System.Drawing.Pens.Black, i, boxSize, i, iGridWidth + boxSize );
                    g.DrawLine( System.Drawing.Pens.Black, boxSize, i, iGridWidth + boxSize, i );
                }
                
            }

            for( int y = 0; y < this.Length; y++ ) {
                for( int x = 0; x < this.Length; x++ ) {
                    if( this.grid[y][x].Content != null ) {
                        var offset = g.MeasureString( this.grid[y][x].ToString(), this.fPreSetCell, boxSize );

                        g.DrawString( 
                            this.grid[y][x].ToString(), 
                            this.grid[y][x].IsPreset?this.fPreSetCell:this.fFilledCell, 
                            this.grid[y][x].IsPreset?System.Drawing.Brushes.Black:this.brFilledCell, 
                            new System.Drawing.RectangleF( 
                                ( x + 1 ) * boxSize + ( boxSize - offset.Width ) / 2, 
                                ( y + 1 ) * boxSize + ( boxSize - offset.Height ) / 2, 
                                boxSize, 
                                boxSize 
                                ) 
                            );
                    }
                }
            }

            return img;
        }
                 
    }

    class Cell {

        public Cell( string content, bool preset ) {
            this.IsPreset = preset;
            this.Content = content;
        }

        internal bool IsPreset {
            get;
            set;
        }

        internal string Content {
            get;
            set;
        }

        public override string ToString() {
            return this.Content;
        }
    }
}
