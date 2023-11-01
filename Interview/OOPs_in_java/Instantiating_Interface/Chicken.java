package com.personal.oops;


//In java multiple inheritance is not possible that means Chickne can have at most 1 parent class only
//but to implement multiple inheritance we can use interface as java can implement multiple interface
public class Chicken extends Bird implements Flyable {
    public Chicken(int age, String gender, int weightInlbs) {
        super(age, gender, weightInlbs);
    }

    //implementing fly abstract method of interface
    public void fly() {
        System.out.println("Not able to fly...");
    }
}
