using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace graph
{
    
    public partial class Form2 : Form
    {
        public Form1 main_form;
        public Form2(Form1 _main_form)
        {
            InitializeComponent();
            this.main_form = _main_form;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string curItem = listBox1.SelectedItem.ToString();
            Console.WriteLine(curItem);

            if (string.Equals("Fire", curItem))
                this.main_form.chart2.Palette = ChartColorPalette.Fire;
            if (string.Equals("SeaGreen", curItem))
                this.main_form.chart2.Palette = ChartColorPalette.SeaGreen;
            if (string.Equals("Berry", curItem))
                this.main_form.chart2.Palette = ChartColorPalette.Berry;
            Refresh();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            //var series = new System.Windows.Forms.DataVisualization.Charting.Series();
            //series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Bar;
            this.main_form.barToolStripMenuItem.Enabled = true;
            this.main_form.lineToolStripMenuItem.Enabled = false;
            //this.chart2.Series.Clear();
            var last_item = this.main_form.chart2.Series.Last();
            last_item.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Bar;
            this.main_form.chart2.Series["Series1"].Points.Clear();
            int last_index = this.main_form.chart2.Series.Count - 1;
            this.main_form.chart2.Series[last_index] = last_item;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            //var series = new System.Windows.Forms.DataVisualization.Charting.Series();
            //series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            this.main_form.barToolStripMenuItem.Enabled = false;
            this.main_form.lineToolStripMenuItem.Enabled = true;
            //this.chart2.Series.Clear();
            var last_item = this.main_form.chart2.Series.Last();
            last_item.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            int last_index = this.main_form.chart2.Series.Count - 1;
            this.main_form.chart2.Series["Series1"].Points.Clear();
            this.main_form.chart2.Series[last_index] = last_item;

        }

        private void button1_Click(object sender, EventArgs e)
        {

            Close();
        }
    }
}
