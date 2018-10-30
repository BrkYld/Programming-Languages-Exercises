using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;
using System.Media;
namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        int visibuSayi = 1; // Görünür ucak sayisini tutacak.
        int uSayi, rSayi = 1;
        int score = 0;
        int hizDegiskeni = 2;
        string labeltext;
        
        

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            SoundPlayer arrow = new SoundPlayer();
            arrow.SoundLocation = @"C:\Users\Yıldırım\Documents\Visual Studio 2015\Projects\WindowsFormsApplication1\WindowsFormsApplication1\arrow4.wav";
            if (e.KeyCode == Keys.Enter && uSayi == 0)
            {
                label4.Visible = false;
                ucakTimer.Enabled = true;
                roketTimer.Enabled = true;
                kontrolTİmer.Enabled = true;
                eklemeTimer.Enabled = true;
            }
            else if (e.KeyCode == Keys.Space && roketTimer.Enabled == true)
            {
                roketEkle();
                //arrow.Play();
                
            }
            else if (e.KeyCode == Keys.A && roketTimer.Enabled == true)
            {
                ucakSavarSol();
            }
            else if (e.KeyCode == Keys.D && roketTimer.Enabled == true)
            {
                ucakSavarSag();
            }

        }

        private void ucakSavarEkle()
        {
            PictureBox a = new PictureBox();
            a.Name = "pcBoxCannon";
            a.Width = 33;
            a.Height = 34;
            a.Location = new Point(425, 415);
            a.Image = Properties.Resources.ucaksavar1;
            this.Controls.Add(a);
        }
        void ucakSavarSol()
        {

            foreach (Control control in Controls)
            {
                if (control.GetType() == typeof(PictureBox))
                {

                    if (control.Name.Contains("pcBoxCannon"))
                    {
                        int index = control.Location.X - control.Width;
                        if (index < 0)
                        {
                            index = control.Location.X;
                        }
                        control.Location = new Point(index, control.Location.Y);
                    }

                }

            }

        }

        void ucakSavarSag()
        {

            foreach (Control control in Controls)
            {
                if (control.GetType() == typeof(PictureBox))
                {

                    if (control.Name.Contains("pcBoxCannon"))
                    {
                        int index = control.Location.X + control.Width;
                        if (index > 875)
                        {
                            index = control.Location.X;
                        }
                        control.Location = new Point(index, control.Location.Y);
                    }

                }

            }




        }
        private void roketEkle()
        {

            PictureBox b = new PictureBox();

            b.Name = "pcBoxRocket" + rSayi;

            b.Width = 15;
            b.Height = 16;
            b.Image = Properties.Resources.mermi;
            this.Controls.Add(b);
            rSayi++;
            foreach (Control control in Controls)
            {
                if (control.GetType() == typeof(PictureBox))
                {

                    if (control.Name.Contains("pcBoxCannon"))
                    {
                        b.Location = new Point(control.Location.X + 10, control.Location.Y - 1);
                    }

                }

            }

        }
        private void ucakEkle()
        {
            PictureBox c = new PictureBox();

            c.Name = "pcBoxUcak" + uSayi;
            c.Location = new Point(RastgeleSayi.SayiUret(5, this.Width - 100), 5);
            c.Width = 71;
            c.Height = 73;
            c.Image = Properties.Resources.ucak1;
            this.Controls.Add(c);
            uSayi++;
            visibuSayi++;
        }

        private void roketHareket(Control rH)
        {
            for (var a = 0; a < 5; a++)
            {
                rH.Location = new Point(rH.Location.X, rH.Location.Y - 1);
                carpismaKontrol();
            }
            if (rH.Location.Y < 0)
            {
                this.Controls.Remove(rH);
            }

        }
        private void ucakHareket(Control uH)
        {

            SoundPlayer defeat = new SoundPlayer();
            defeat.SoundLocation = @"C:\Users\Yıldırım\Documents\Visual Studio 2015\Projects\WindowsFormsApplication1\WindowsFormsApplication1\defeat.wav";

            uH.Location = new Point(uH.Location.X, uH.Location.Y + 1);
            carpismaKontrol();

            if (uH.Location.Y > 413)
            {
                label3.Visible = true;
                this.Controls.Remove(uH);
                eklemeTimer.Enabled = false;
                ucakTimer.Enabled = false;
                roketTimer.Enabled = false;
                //defeat.Play();
               
            }








        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.FormBorderStyle = FormBorderStyle.FixedSingle;//Boyutu sabitlemeye yarar.
            ucakSavarEkle();
        }

        private void ucakTimer_Tick(object sender, EventArgs e)
        {


            foreach (Control control in Controls)
            {
                if (control.GetType() == typeof(PictureBox))
                {

                    if (control.Name.Contains("pcBoxUcak"))
                    {
                        ucakHareket(control);
                    }






                }

            }
        }

        private void kontrolTİmer_Tick(object sender, EventArgs e)
        {
            carpismaKontrol();



        }

        private void carpismaKontrol()
        {
            SoundPlayer patlama = new SoundPlayer();
            patlama.SoundLocation = @"C:\Users\Yıldırım\Documents\Visual Studio 2015\Projects\WindowsFormsApplication1\WindowsFormsApplication1\cannon4_new.wav";
            foreach (Control roket in Controls)
            {
                if (roket.GetType() == typeof(PictureBox))
                {
                    if (roket.Name.Contains("pcBoxRocket") && roket.Visible)
                    {
                        foreach (Control ucak in Controls)
                        {
                            if (ucak.GetType() == typeof(PictureBox))
                            {
                                if (ucak.Name.Contains("pcBoxUcak") && ucak.Visible)
                                {
                                    if (roket.Location.X >= ucak.Location.X && roket.Location.X <= ucak.Location.X + ucak.Width
                                    && (ucak.Location.Y + ucak.Height == roket.Location.Y + roket.Height))
                                    {
                                        this.Controls.Remove(roket);
                                        this.Controls.Remove(ucak);
                                        visibuSayi--;
                                        score = score + 100;
                                        labeltext = Convert.ToString(score);
                                        label2.Text = labeltext;
                                        //patlama.Play();
                                    }

                                }
                            }
                        }
                    }
                }
            }

        }

        private void eklemeTimer_Tick(object sender, EventArgs e)//Ucak sayisi artirma.
        {
            if (visibuSayi <= hizDegiskeni)
            {
                ucakEkle();
            }

            if (score % 1000 == 0 && score != 0)
            {
                hizDegiskeni++;
                score = score + 100;
            }


        }

        private void roketTimer_Tick(object sender, EventArgs e)
        {
            foreach (Control control in Controls)
            {
                if (control.GetType() == typeof(PictureBox))
                {

                    if (control.Name.Contains("pcBoxRocket"))
                    {
                        roketHareket(control);

                    }
                }

            }
        }

      

        private void label1_Click(object sender, EventArgs e)
        {
            label1.Enabled = false;
        }

        private void label2_Click(object sender, EventArgs e)
        {
            label2.Enabled = true;
        }

        private void label3_Click(object sender, EventArgs e)
        {
            label3.Visible = false;
        }

       
    }
    class RastgeleSayi
    {
        public static int SayiUret(int min, int max)
        {
            if (rastgele == null)
                rastgele = new Random();

            return rastgele.Next(min, max);
        }

        private static Random rastgele;
    }
}
