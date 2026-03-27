## Description:

Create a "Hello World!" program in Java, set up a build system for it, and get used to debugging it.

## What I learned:

- setting up a basic pom.xml file, using maven to build the java app
- dealing with compiled java files

```bash
mvn compile
mvn package
java -cp target/classes src.main.java.com.challenge2.Main
```

using maven runner can now perform

```bash
mvn exec:java
```