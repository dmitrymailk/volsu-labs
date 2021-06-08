using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Windows.Forms.DataVisualization.Charting;

namespace graph
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            openFileDialog1.Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
            saveFileDialog1.Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
            chart2.ChartAreas[0].RecalculateAxesScale();
        }

        //Массивы для хранения
        public List<int> x;
        public List<int> y;
        int[] a;
        int graph_type = 0;
        private void ОткрытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    //Инициализация массивов
                    x = new List<int>();
                    y = new List<int>();

                    //Чтение файла и запись значений в List x и y
                    StreamReader sr = new StreamReader(openFileDialog1.FileName);
                    string line;
                    string[] line2;
                    while ((line = sr.ReadLine()) != null)
                    {
                        line2 = line.Split(','); //разбиваем строку на подстроки
                        x.Add(Convert.ToInt32(line2[0]));
                        y.Add(Convert.ToInt32(line2[1]));
                    }
                    sr.Close();

                    
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }
        }

        private void quitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }


        private void quitToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void chart2_Click(object sender, EventArgs e)
        {

        }



        private void barToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.chart2.Series["Series1"].Points.Clear();
            this.Text = "Bar Graph";
            //Добавляем точки на график
            foreach (int val in this.x)
                this.chart2.Series["Series1"].Points.Add(val);
        }

        private void chooseToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 newForm = new Form2(this);
            newForm.Show();
        }

        private void lineToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.chart2.Series["Series1"].Points.Clear();
            this.Text = "Line Graph";
            //Добавляем точки на график
            foreach (int val in this.x)
                this.chart2.Series["Series1"].Points.Add(val);
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            chart2.Width = Width - 10;
            chart2.Height = Height - 10;
        }
    }
    
}