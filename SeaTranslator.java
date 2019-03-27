import java.io.*; 

class SeaTranslator { 
    public static void main(String[] args) throws Exception { 
        File inputFile = new File ("test.sea"); 
        SeaParser parser = new SeaParser(new SeaScanner(new FileInputStream(inputFile)));
        // Program program =(Program)parser.parse().value;
        // program.build();
        String program = (String)parser.parse().value;

        FileWriter fw=new FileWriter(new File("sea.c")); 
        fw.write(program);
        fw.close(); 
    } 
} 