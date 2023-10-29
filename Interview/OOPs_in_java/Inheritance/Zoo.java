package com.personal.oops;

public class Zoo {
    public static void main(String[] arg) {

        Animal animal1 = new Animal(12, "M", 12);
        animal1.eat();

        //OBJECTS exist during application runtime
        Bird bird1 = new Bird(1, "m", 15);
        bird1.fly();
        bird1.eat();

        Fish fish1 = new Fish(2, "f", 16);
        fish1.swim();
        fish1.sleep();
    }
}
