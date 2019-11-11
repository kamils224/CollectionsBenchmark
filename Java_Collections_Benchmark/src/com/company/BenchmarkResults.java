package com.company;

public class BenchmarkResults {

    public long CreateAndAddTime;
    public long AddTime;
    public long FindTime;
    public long RemoveTime;

    @Override
    public String toString() {
        return String.format("Create and add: %1$s\n" +
                "Add: %2$s\n" +
                "Find: %3$s\n" +
                "Remove: %4$s\n",
                CreateAndAddTime, AddTime, FindTime, RemoveTime);
    }
}
