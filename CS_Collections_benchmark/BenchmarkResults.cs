using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Collections_benchmark
{
    class BenchmarkResults
    {
        public long AddTime { get; set; }
        public long FindTime { get; set; }
        public long RemoveTime { get; set; }

        public override string ToString()
        {
            return string.Format("Add: {0}\n" +
                "Find: {1}\n" +
                "Remove: {2}\n",
                AddTime, FindTime, RemoveTime);
        }

    }
}
