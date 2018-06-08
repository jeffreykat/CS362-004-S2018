

import junit.framework.TestCase;
import static org.junit.Assert.*;
import static org.junit.runners.Parameterized.*;
import org.junit.Test;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {
	static String[] valid = {"http://www.google.com",
			"ftp://123.32.0.193",
			"0.0.0.0/t123",
			"255.com/test1",
			"https://john.doe@www.example.com:123/forum/questions/?tag=networking&order=newest#top",
			"ldap://[2001:db8::7]/c=GB?objectClass?one",
			"mailto:John.Doe@example.com",
			"news:comp.infosystems.www.servers.unix",
			"tel:+1-816-555-1212",
			"telnet://192.0.2.16:80/",
			"urn:oasis:names:specification:docbook:dtd:xml:4.1.2"};
	static String[] invalid = {"http:///w.google",
			"://1.2.3.4.5:80",
			"http://255.com:-1/test1",
			"ftp://go.com:65a/../",
			":80/t23",
			""};
	

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   @Test
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, 0);
	   
	   for(int i = 0; i < valid.length; i++) {
		   assertEquals(String.format("Fail valid case:%s",valid[i]),urlVal.isValid(valid[i]),true);
	   }
	   
	   for(int i = 0; i < invalid.length; i++) {
		   assertEquals(String.format("Fail invalid case:%s",invalid[i]),urlVal.isValid(invalid[i]),false);
	   }
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
