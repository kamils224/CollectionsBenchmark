package com.company;

import java.util.ArrayList;
import java.util.List;

public class ArrayListTest implements IBenchmark {

    List<Integer> list;
    int numOfOperations;

    public ArrayListTest(){
        list = new ArrayList<>();
        this.numOfOperations = 100;
    }

    public ArrayListTest(int numOfOperations){
        list = new ArrayList<>();
        this.numOfOperations = numOfOperations;
    }


    @Override
    public void AddTest() {
        for (int i = 0; i < numOfOperations; i++){
            list.add(i);
        }
    }

    @Override
    public void FindTest() {
        int toFind = list.size()-1;
        for (int i =0; i < numOfOperations; i++){
            boolean result = list.contains(toFind);
        }
    }

    @Override
    public void RemoveTest() {
        for (int i = 0; i< list.size(); i++){
            Integer toRemove = list.get(0);
            list.remove(toRemove);
        }
    }
}
