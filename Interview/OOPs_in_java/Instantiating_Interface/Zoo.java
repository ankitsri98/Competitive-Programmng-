package com.personal.oops;

public class Zoo {
    public static void main(String[] arg) {

       /*
       INSTANTIATING INTERFACE : f. only Flyable class methods are available and class will only be the one who is implementing it.
        */
            Flyable f = new Sparrow(1,"m",13);
            f.fly();
    }
}
