package com.company;

import java.io.*;
import java.util.List;

public class ResultsManager {

    private final String collectionInfo = "Collection name: %1$s,number of operations: %2$s,unit: %3$s";
    private final String columns = "Add time,Find time,Remove time";
    private final String rowPattern = "%1$s,%2$s,%3$s";
    private final String measureUnit = "ms";
    public String CollectionName = "None";
    public int NumberOfOperations = 0;


    public void SaveToCsv(List<BenchmarkResults> results, String path) throws IOException {
        StringBuilder csv = new StringBuilder();
        String firstRow = String.format
                (collectionInfo, CollectionName, NumberOfOperations, measureUnit);

        String newLine = System.lineSeparator();
        csv.append(firstRow).append(newLine);
        csv.append(columns).append(newLine);

        for (int i = 0; i < results.size(); i++)
        {
            String row = String.format
                    (rowPattern,
                            results.get(i).AddTime, results.get(i).FindTime, results.get(i).RemoveTime);

            csv.append(row).append(newLine);
        }

        BufferedWriter writer = new BufferedWriter(new FileWriter(path));
        writer.write(csv.toString());

        writer.close();

    }
}
