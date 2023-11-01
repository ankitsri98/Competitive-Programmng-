package com.personal.oops;

public class Chicken extends Bird {
    public Chicken(int age, String gender, int weightInlbs) {
        super(age, gender, weightInlbs);
    }

    //Here i'm overriding the fly method of Bird parent class and describing the behaviour
    //from chicken class object this fly method will be called now.
    public void fly() {
        System.out.println("Not able to fly...");
    }
}
