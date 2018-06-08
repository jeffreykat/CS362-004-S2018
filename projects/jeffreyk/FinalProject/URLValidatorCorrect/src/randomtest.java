import java.util.Random;

public class randomtest {
   static String[] schemes = {"http","https","ftp","err",""};
   static String[] schemesEx = {"","://", ":/", ":"};
   static String[] authorities = {"0.0.0.0","","www.google.com","github.com","255.com","test.er","test","255.255.255.255"};
   static String[] paths = {"/test/file","/../","/","","/test/","/..//test"};
   static String[] ports = {":0",":test",":20","",":50009"};

   /*Create random URL*/
   public static String makeString(){
      StringBuilder sb = new StringBuilder();
      Random rand = new Random();
      int scheme = rand.nextInt(5);
      sb = sb.append(schemes[scheme]);
      int schemeEx = rand.nextInt(4);
      sb = sb.append(schemesEx[schemeEx]);
      int authority = rand.nextInt(8);
      sb = sb.append(authorities[authority]);
      int path = rand.nextInt(6);
      sb = sb.append(paths[path]);
      int port = rand.nextInt(5);
      sb = sb.append(ports[port]);
      return sb.toString();
   }

   /*Use isValid to test URL*/
   public static boolean testIsValid(){
      UrlValidator urlVal = new UrlValidator(null, null, 0);
      String url = makeString();
      System.out.println(url);
      return (urlVal.isValid(url));
   }

   public static void main(String[] argv) {
      int fails = 0;
      boolean res = false;
      for(int i = 0; i < 20; i++){
	 res = testIsValid();
	 if(!(res)){
	    System.out.println("FAIL");
	    fails++;
	 }
	 else
	    System.out.println("PASS");
      }
      System.out.println(fails);
   }
}
