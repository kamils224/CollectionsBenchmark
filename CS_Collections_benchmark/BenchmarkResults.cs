using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Collections_benchmark
{
    class BenchmarkResults
    {
        public double AddTime { get; set; }
        public double FindTime { get; set; }
        public double RemoveTime { get; set; }

        public override string ToString()
        {
            return string.Format("Add: {0}\n" +
                "Find: {1}\n" +
                "Remove: {2}\n",
                AddTime, FindTime, RemoveTime);
        }

    }
}
