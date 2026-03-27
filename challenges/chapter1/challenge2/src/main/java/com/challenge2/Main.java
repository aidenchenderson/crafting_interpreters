// Challenge 2, Hello World (with a few tweaks, 'cause why not)
package src.main.java.com.challenge2;

class Main {
    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Usage: java src.main.java.com.challenge2.Main <arg_1> ...");
            return;
        }

        System.out.println("Hello World! Here is your input:");
        for (int i = 0; i < args.length; i++) {
            String arg = String.format("argument: %s", args[i]);
            System.out.println(arg);
        }
    }
}