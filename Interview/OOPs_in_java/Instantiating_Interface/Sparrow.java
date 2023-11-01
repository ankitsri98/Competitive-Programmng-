package com.personal.oops;

public class Sparrow extends Bird implements Flyable{

    public Sparrow(int age, String gender, int weightInlbs) {
        super(age, gender, weightInlbs);
    }

    //implementing fly abstract method of interface
    public void fly() {
        System.out.println("I can Fly high....");
    }
}
