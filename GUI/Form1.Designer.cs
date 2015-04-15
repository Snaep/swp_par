namespace GUI {
    partial class Form1 {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose( bool disposing ) {
            if( disposing && ( components != null ) ) {
                components.Dispose();
            }
            base.Dispose( disposing );
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.sudokuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.neuGenerierenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.oeffnenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.speichernToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.speichernUnterStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.beendenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sudokuoeffnenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.größeToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripTextBox1 = new System.Windows.Forms.ToolStripTextBox();
            this.schwierigkeitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.leichtToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.normalToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.schwerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lösungToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.strategienToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.parallelisierungToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.überToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.generierenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lösenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.menuStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            ( ( System.ComponentModel.ISupportInitialize )( this.pictureBox1 ) ).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.sudokuToolStripMenuItem,
            this.sudokuoeffnenToolStripMenuItem,
            this.lösungToolStripMenuItem,
            this.überToolStripMenuItem} );
            this.menuStrip1.Location = new System.Drawing.Point( 0, 0 );
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size( 561, 24 );
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // sudokuToolStripMenuItem
            // 
            this.sudokuToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.neuGenerierenToolStripMenuItem,
            this.oeffnenToolStripMenuItem,
            this.toolStripSeparator1,
            this.speichernToolStripMenuItem,
            this.speichernUnterStripMenuItem2,
            this.toolStripSeparator2,
            this.toolStripMenuItem1,
            this.toolStripMenuItem2,
            this.toolStripSeparator3,
            this.beendenToolStripMenuItem} );
            this.sudokuToolStripMenuItem.Name = "sudokuToolStripMenuItem";
            this.sudokuToolStripMenuItem.Size = new System.Drawing.Size( 50, 20 );
            this.sudokuToolStripMenuItem.Text = "Menu";
            // 
            // neuGenerierenToolStripMenuItem
            // 
            this.neuGenerierenToolStripMenuItem.Name = "neuGenerierenToolStripMenuItem";
            this.neuGenerierenToolStripMenuItem.ShortcutKeyDisplayString = "";
            this.neuGenerierenToolStripMenuItem.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.N ) ) );
            this.neuGenerierenToolStripMenuItem.Size = new System.Drawing.Size( 238, 22 );
            this.neuGenerierenToolStripMenuItem.Text = "Neu";
            this.neuGenerierenToolStripMenuItem.Click += new System.EventHandler( this.neuGenerierenToolStripMenuItem_Click );
            // 
            // oeffnenToolStripMenuItem
            // 
            this.oeffnenToolStripMenuItem.Name = "oeffnenToolStripMenuItem";
            this.oeffnenToolStripMenuItem.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O ) ) );
            this.oeffnenToolStripMenuItem.Size = new System.Drawing.Size( 238, 22 );
            this.oeffnenToolStripMenuItem.Text = "Öffnen";
            this.oeffnenToolStripMenuItem.Click += new System.EventHandler( this.oeffnenToolStripMenuItem_Click );
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size( 235, 6 );
            // 
            // speichernToolStripMenuItem
            // 
            this.speichernToolStripMenuItem.Name = "speichernToolStripMenuItem";
            this.speichernToolStripMenuItem.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S ) ) );
            this.speichernToolStripMenuItem.Size = new System.Drawing.Size( 238, 22 );
            this.speichernToolStripMenuItem.Text = "Speichern";
            this.speichernToolStripMenuItem.Click += new System.EventHandler( this.speichernToolStripMenuItem_Click );
            // 
            // speichernUnterStripMenuItem2
            // 
            this.speichernUnterStripMenuItem2.Name = "speichernUnterStripMenuItem2";
            this.speichernUnterStripMenuItem2.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift )
            | System.Windows.Forms.Keys.S ) ) );
            this.speichernUnterStripMenuItem2.Size = new System.Drawing.Size( 238, 22 );
            this.speichernUnterStripMenuItem2.Text = "Speichern unter...";
            this.speichernUnterStripMenuItem2.Click += new System.EventHandler( this.speichernUnterStripMenuItem2_Click );
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size( 235, 6 );
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.ShortcutKeyDisplayString = "";
            this.toolStripMenuItem1.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.C ) ) );
            this.toolStripMenuItem1.Size = new System.Drawing.Size( 238, 22 );
            this.toolStripMenuItem1.Text = "Kopieren";
            this.toolStripMenuItem1.Click += new System.EventHandler( this.toolStripMenuItem1_Click );
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.V ) ) );
            this.toolStripMenuItem2.Size = new System.Drawing.Size( 238, 22 );
            this.toolStripMenuItem2.Text = "Einfügen";
            this.toolStripMenuItem2.Click += new System.EventHandler( this.toolStripMenuItem2_Click );
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size( 235, 6 );
            // 
            // beendenToolStripMenuItem
            // 
            this.beendenToolStripMenuItem.Name = "beendenToolStripMenuItem";
            this.beendenToolStripMenuItem.ShortcutKeys = ( ( System.Windows.Forms.Keys )( ( System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F4 ) ) );
            this.beendenToolStripMenuItem.Size = new System.Drawing.Size( 238, 22 );
            this.beendenToolStripMenuItem.Text = "Beenden";
            this.beendenToolStripMenuItem.Click += new System.EventHandler( this.beendenToolStripMenuItem_Click );
            // 
            // sudokuoeffnenToolStripMenuItem
            // 
            this.sudokuoeffnenToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.größeToolStripMenuItem,
            this.schwierigkeitToolStripMenuItem,
            this.toolStripSeparator4,
            this.generierenToolStripMenuItem,
            this.lösenToolStripMenuItem} );
            this.sudokuoeffnenToolStripMenuItem.Name = "sudokuoeffnenToolStripMenuItem";
            this.sudokuoeffnenToolStripMenuItem.Size = new System.Drawing.Size( 59, 20 );
            this.sudokuoeffnenToolStripMenuItem.Text = "Sudoku";
            // 
            // größeToolStripMenuItem
            // 
            this.größeToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.toolStripTextBox1} );
            this.größeToolStripMenuItem.Name = "größeToolStripMenuItem";
            this.größeToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.größeToolStripMenuItem.Text = "Größe";
            // 
            // toolStripTextBox1
            // 
            this.toolStripTextBox1.Name = "toolStripTextBox1";
            this.toolStripTextBox1.Size = new System.Drawing.Size( 100, 23 );
            this.toolStripTextBox1.Text = "9";
            this.toolStripTextBox1.TextBoxTextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.toolStripTextBox1.KeyDown += new System.Windows.Forms.KeyEventHandler( this.toolStripTextBox1_KeyDown );
            // 
            // schwierigkeitToolStripMenuItem
            // 
            this.schwierigkeitToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.leichtToolStripMenuItem,
            this.normalToolStripMenuItem,
            this.schwerToolStripMenuItem} );
            this.schwierigkeitToolStripMenuItem.Name = "schwierigkeitToolStripMenuItem";
            this.schwierigkeitToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.schwierigkeitToolStripMenuItem.Text = "Schwierigkeit";
            // 
            // leichtToolStripMenuItem
            // 
            this.leichtToolStripMenuItem.Name = "leichtToolStripMenuItem";
            this.leichtToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.leichtToolStripMenuItem.Text = "Leicht";
            this.leichtToolStripMenuItem.Click += new System.EventHandler( this.leichtToolStripMenuItem_Click );
            // 
            // normalToolStripMenuItem
            // 
            this.normalToolStripMenuItem.Checked = true;
            this.normalToolStripMenuItem.CheckState = System.Windows.Forms.CheckState.Checked;
            this.normalToolStripMenuItem.Name = "normalToolStripMenuItem";
            this.normalToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.normalToolStripMenuItem.Text = "Normal";
            this.normalToolStripMenuItem.Click += new System.EventHandler( this.normalToolStripMenuItem_Click );
            // 
            // schwerToolStripMenuItem
            // 
            this.schwerToolStripMenuItem.Name = "schwerToolStripMenuItem";
            this.schwerToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.schwerToolStripMenuItem.Text = "Schwer";
            this.schwerToolStripMenuItem.Click += new System.EventHandler( this.schwerToolStripMenuItem_Click );
            // 
            // lösungToolStripMenuItem
            // 
            this.lösungToolStripMenuItem.DropDownItems.AddRange( new System.Windows.Forms.ToolStripItem[] {
            this.strategienToolStripMenuItem,
            this.parallelisierungToolStripMenuItem} );
            this.lösungToolStripMenuItem.Name = "lösungToolStripMenuItem";
            this.lösungToolStripMenuItem.Size = new System.Drawing.Size( 58, 20 );
            this.lösungToolStripMenuItem.Text = "Lösung";
            // 
            // strategienToolStripMenuItem
            // 
            this.strategienToolStripMenuItem.Name = "strategienToolStripMenuItem";
            this.strategienToolStripMenuItem.Size = new System.Drawing.Size( 154, 22 );
            this.strategienToolStripMenuItem.Text = "Strategien";
            this.strategienToolStripMenuItem.Click += new System.EventHandler( this.strategienToolStripMenuItem_Click );
            // 
            // parallelisierungToolStripMenuItem
            // 
            this.parallelisierungToolStripMenuItem.Name = "parallelisierungToolStripMenuItem";
            this.parallelisierungToolStripMenuItem.Size = new System.Drawing.Size( 154, 22 );
            this.parallelisierungToolStripMenuItem.Text = "Parallelisierung";
            this.parallelisierungToolStripMenuItem.Click += new System.EventHandler( this.parallelisierungToolStripMenuItem_Click );
            // 
            // überToolStripMenuItem
            // 
            this.überToolStripMenuItem.Name = "überToolStripMenuItem";
            this.überToolStripMenuItem.Size = new System.Drawing.Size( 40, 20 );
            this.überToolStripMenuItem.Text = "Info";
            this.überToolStripMenuItem.Click += new System.EventHandler( this.überToolStripMenuItem_Click );
            // 
            // panel1
            // 
            this.panel1.AutoScroll = true;
            this.panel1.Controls.Add( this.pictureBox1 );
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point( 0, 24 );
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size( 561, 337 );
            this.panel1.TabIndex = 1;
            this.panel1.SizeChanged += new System.EventHandler( this.panel1_SizeChanged );
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point( 0, 0 );
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size( 100, 50 );
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.Filter = "Sudoku|*.sud|Alle Dateien|*.*";
            this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler( this.openFileDialog1_FileOk );
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.Filter = "Sudoku|*.sud|Alle Dateien|*.*";
            this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler( this.saveFileDialog1_FileOk );
            // 
            // generierenToolStripMenuItem
            // 
            this.generierenToolStripMenuItem.Name = "generierenToolStripMenuItem";
            this.generierenToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F5;
            this.generierenToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.generierenToolStripMenuItem.Text = "Generieren";
            this.generierenToolStripMenuItem.Click += new System.EventHandler( this.generierenToolStripMenuItem_Click );
            // 
            // lösenToolStripMenuItem
            // 
            this.lösenToolStripMenuItem.Name = "lösenToolStripMenuItem";
            this.lösenToolStripMenuItem.ShortcutKeys = System.Windows.Forms.Keys.F6;
            this.lösenToolStripMenuItem.Size = new System.Drawing.Size( 152, 22 );
            this.lösenToolStripMenuItem.Text = "Lösen";
            this.lösenToolStripMenuItem.Click += new System.EventHandler( this.lösenToolStripMenuItem_Click );
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size( 149, 6 );
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF( 6F, 13F );
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size( 561, 361 );
            this.Controls.Add( this.panel1 );
            this.Controls.Add( this.menuStrip1 );
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.menuStrip1.ResumeLayout( false );
            this.menuStrip1.PerformLayout();
            this.panel1.ResumeLayout( false );
            this.panel1.PerformLayout();
            ( ( System.ComponentModel.ISupportInitialize )( this.pictureBox1 ) ).EndInit();
            this.ResumeLayout( false );
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem sudokuToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem neuGenerierenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem speichernToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem beendenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lösungToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem strategienToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem parallelisierungToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem oeffnenToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem speichernUnterStripMenuItem2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStripMenuItem sudokuoeffnenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem größeToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem schwierigkeitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem leichtToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem normalToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem schwerToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem überToolStripMenuItem;
        private System.Windows.Forms.ToolStripTextBox toolStripTextBox1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem generierenToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem lösenToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
    }
}

