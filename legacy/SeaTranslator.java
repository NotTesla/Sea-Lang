import java.io.*; 

class SeaTranslator { 
    public static void main(String[] args) throws Exception { 
        File inputFile = new File ("test.sea"); 
        SeaParser parser = new SeaParser(new SeaScanner(new FileInputStream(inputFile)));
        Expression program =(Expression)parser.parse().value;
        program.build();

        FileWriter fw=new FileWriter(new File("sea.c"));
        fw.write(program.code);
        fw.close();
    }
}
