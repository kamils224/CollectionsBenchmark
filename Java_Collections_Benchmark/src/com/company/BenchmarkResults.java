package com.company;

public class BenchmarkResults {

    public double CreateAndAddTime;
    public double AddTime;
    public double FindTime;
    public double RemoveTime;

    @Override
    public String toString() {
        return String.format("Create and add: %1$s\n" +
                "Add: %2$s\n" +
                "Find: %3$s\n" +
                "Remove: %4$s\n",
                CreateAndAddTime, AddTime, FindTime, RemoveTime);
    }
}
