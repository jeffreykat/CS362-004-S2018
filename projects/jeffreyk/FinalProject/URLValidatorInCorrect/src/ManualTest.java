/*
 * Manual Tests - Katherine Jeffrey
 */

public class ManualTest{
   static String[] valid = {"http://www.google.com","ftp://123.32.0.193","www.google.com/test123","0.0.0.0/t123","255.com/test1"};
   static String[] invalid = {"://1.2.3.4.5:80","http://255.com:-1/test1","ftp://go.com:65a/../",":80/t23",""};

   public static void main(String[] argv){
      UrlValidator urlVal = new UrlValidator(null, null, 0);
      boolean check = false;
      int fails = 0;
      for(int i = 0; i < valid.length; i++){
	 check = urlVal.isValid(valid[i]);
	 if(!(check))
	    fails++;
      }
      System.out.print("Incorrect: ");
      System.out.print(fails);
      System.out.println("/5");
      fails = 0;
      for(int j = 0; j < invalid.length; j++){
	 check = urlVal.isValid(invalid[j]);
	 if(check)
	    fails++;
      }
      System.out.print("Fails: ");
      System.out.print(fails);
      System.out.println("/5");
   }
}
