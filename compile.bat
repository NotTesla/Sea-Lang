del *.class sea.c
java JLex.Main sea.lex
java java_cup.Main -parser SeaParser -symbols SeaSymbol < sea.cup 
javac sea.lex.java SeaParser.java SeaSymbol.java SeaCompiler.java 
java SeaCompiler
del *.class