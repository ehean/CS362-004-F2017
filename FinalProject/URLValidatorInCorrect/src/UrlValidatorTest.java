/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   /* MANUAL TEST SCHEMES */
	   System.out.println("VALID MANUAL TEST SCHEMES");
	   
	   /* EXPECTED RESULT: PASS */
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("https://www.amazon.com"));
	   System.out.println(urlVal.isValid("h3t://www.amazon.com"));
	   
	   // THIS RETURNS A FALSE NEGATIVE
	   System.out.println(urlVal.isValid("www.amazon.com"));
	   System.out.println(urlVal.isValid("ftp://www.amazon.com"));
	   System.out.println(urlVal.isValid("Http://www.amazon.com"));
	  
	   
	   /* EXPECTED RESULT: FAIL */
	   System.out.println("INVALID MANUAL TEST SCHEMES");
	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
	   System.out.println(urlVal.isValid("http:www.amazon.com"));
	   System.out.println(urlVal.isValid("http//www.amazon.com"));
	   System.out.println(urlVal.isValid("://www.amazon.com"));
	   System.out.println(urlVal.isValid("http:\\www.amazon.com"));
	   
	   
	   /* MANUAL TEST AUTHORITY */
	   
	   System.out.println("VALID MANUAL TEST AUTHORITIES");
	   
	   /* EXPECTED RESULT: PASS */
	   System.out.println(urlVal.isValid("http://amazon.com"));
	   
	   /* RETURNS FALSE NEGATIVE */
	   System.out.println(urlVal.isValid("http://amazon.nz"));
	   System.out.println(urlVal.isValid("http://0.0.0.0"));
	   System.out.println(urlVal.isValid("http://255.255.255.255"));
	   System.out.println(urlVal.isValid("http://128.com"));
	   System.out.println(urlVal.isValid("http://amazon.gov"));
	   
	   /* EXPECTED RESULT: FAIL */
	   System.out.println("INVALID MANUAL TEST AUTHORITIES");
	   System.out.println(urlVal.isValid("http://amaz/on.com"));
	   System.out.println(urlVal.isValid("http://amazon.nzs"));
	   System.out.println(urlVal.isValid("http://0.0.0.-1"));
	   
	   /* RETURNS FALSE POSITIVE */
	   System.out.println(urlVal.isValid("http://255.255.255.256"));
	   System.out.println(urlVal.isValid("http://128..com"));
	   System.out.println(urlVal.isValid("http://amaz?on.gov"));
	   
	   
	   /* MANUAL TEST PORT */
	   
	   System.out.println("VALID MANUAL TEST PORTS");
	   
	   /* EXPECTED RESULT: PASS */
	   System.out.println(urlVal.isValid("http://www.amazon.com:80"));
	   
	   /* RETURNS FALSE NEGATIVE */
	   System.out.println(urlVal.isValid("http://www.amazon.com:65535"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:0"));
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:034"));
	   
	   /* EXPECTED RESULT: FAIL */
	   System.out.println("INVALID MANUAL TEST AUTHORITIES");
	   System.out.println(urlVal.isValid("http://www.amazon.com:"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:s"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:-1"));
	   System.out.println(urlVal.isValid("http://www.amazon.com;0"));
	   System.out.println(urlVal.isValid("http://www.amazon.com:09348248"));
	   
	   /*Test Paths*/
	   //void path
	   assertTrue("An otherwise valid URL with a void path should be valid.", urlVal.isValid("http://www.google.com:80"));
	   //single valid xpalphas paths
	   assertTrue("An otherwise valid URL with a single '+' path should be valid.", urlVal.isValid("http://www.google.com:80/+"));
	   assertTrue("An otherwise valid URL with a single alpha 'a' path should be valid.", urlVal.isValid("http://www.google.com:80/a"));
	   assertTrue("An otherwise valid URL with a single digit '0' path should be valid.", urlVal.isValid("http://www.google.com:80/0"));
	   assertTrue("An otherwise valid URL with a single safe '$' path should be valid.", urlVal.isValid("http://www.google.com:80/$"));
	   assertTrue("An otherwise valid URL with a single extra '!' path should be valid.", urlVal.isValid("http://www.google.com:80/!"));
	   assertTrue("An otherwise valid URL with a single escape '%aa' path should be valid.", urlVal.isValid("http://www.google.com:80/%aa"));
	   //multiple xpalphas path delimited by forward slashes
	   assertTrue("An otherwise valid URL with xpalphas/xpalphas/ path should be valid.", urlVal.isValid("http://www.google.com:80/+a0$!%aa/+a0$!%aa/+a0$!%aa/"));
	   //single invalid char paths
	   assertFalse("An otherwise valid URL with a single reserved character '?' path should be invalid.", urlVal.isValid("http://www.google.com:80/?"));
	   assertFalse("An otherwise valid URL with a single national character '{' path should be invalid.", urlVal.isValid("http://www.google.com:80/{"));
	   assertFalse("An otherwise valid URL with a single punctuation character '<' path should be invalid.", urlVal.isValid("http://www.google.com:80/<"));
	   //multiple invalid character paths delimited by forward slashes
	   assertFalse("An otherwise valid URL with /invalidChars/invalidChars/ path should be invalid.", urlVal.isValid("http://www.google.com:80/?{</?{</?{</?{</"));
	   //one valid character and one invalid character
	   assertFalse("An otherwise valid URL with invalidChar+xpalphas path should be invalid.", urlVal.isValid("http://www.google.com:80/{a"));
	   //mixing of invalid characters and invalid character paths delimited by forward slashes
	   assertFalse("An otherwise valid URL with /invalidChars+validChars/invalidChars+validChars/ path should be invalid.", urlVal.isValid("http://www.google.com:80/+a0$!%aa?{</+a0$!%aa?{</"));
	   /*Test Queries*/
	   //void query
	   assertTrue("An otherwise valid URL with a void query should be valid.", urlVal.isValid("http://www.google.com:80/"));
	   //? query
	   assertTrue("An otherwise valid URL with a query beginning with '?' to the end of the URL with no '#' should be valid.", urlVal.isValid("http://www.google.com:80/?a1+}{!@$%&^*"));
	   //?##
	   assertFalse("An otherwise valid URL with a query ending in'##' should be invalid as '#' starts a fragment and '#' is not a valid fragment.", urlVal.isValid("http://www.google.com:80/?##"));
   }
   
   
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   /* MANUAL TEST PATHS */
	   System.out.println("VALID TEST PATHS");
	   
	   /* EXPECTED RESULT: PASS */
	   System.out.println(urlVal.isValid("http://www.amazon.com"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/test"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/123"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/@"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/&"));
	   
	   /* NOT SURE WHY '?' RETURNS FALSE */
	   System.out.println(urlVal.isValid("http://www.amazon.com/?"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/="));
	   System.out.println(urlVal.isValid("http://www.amazon.com/+"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/,"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/."));
	   System.out.println(urlVal.isValid("http://www.amazon.com/!"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/~"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/*"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/'"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/%"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/$"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/_"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/;"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/("));
	   System.out.println(urlVal.isValid("http://www.amazon.com/)"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/test/"));
	   
	   
	   /* MANUAL TEST PATHS */
	   System.out.println("INVALID TEST PATHS");
	   
	   /* EXPECTED RESULT: FAIL */
	   System.out.println(urlVal.isValid("http://www.amazon.com/\\"));
	   System.out.println(urlVal.isValid("http://www.amazon.com["));
	   System.out.println(urlVal.isValid("http://www.amazon.com/]"));
	   
	   /* NOT SURE WHY '//' RETURNS FALSE */
	   System.out.println(urlVal.isValid("http://www.amazon.com//"));
	   System.out.println(urlVal.isValid("http://www.amazon.com/(("));
	   System.out.println(urlVal.isValid("http://www.amazon.com/~~"));
	   
	   
//	   String tooLong = null;
//	   for (int i = 0; i < Integer.MAX_VALUE; i++) {
//		   tooLong += "a";
//	   }
//	   
//	   
//	   System.out.println(urlVal.isValid("http://www.amazon.com/" + tooLong));
	   
	   
	   
	   Integer intTest = 1;
	   System.out.println(urlVal.isValid("http://www.amazon.com/" + intTest));
	   Boolean boolTest = true;
	   System.out.println(urlVal.isValid("http://www.amazon.com/" + boolTest));	 
	   Double floatTest = 1.0;
	   System.out.println(urlVal.isValid("http://www.amazon.com/" + floatTest));
	   Character charTest = 'a';
	   System.out.println(urlVal.isValid("http://www.amazon.com/" + charTest));
	   
	   
	   
	   /* VALID QUERY TESTS */
	   System.out.println("VALID QUERY PATHS");
	   
	   System.out.println(urlVal.isValid("http://www.amazon.com/test?action=view"));
   }
   
   public void testYourSecondPartition(){
	   
   }
   //Test authorities in the IPv4 format [0.0.0.0, 255.255.255.255] and reg-name host name format: dot delimited [a,z] [0,9], - https://en.wikipedia.org/wiki/Hostname
   public void testAuthorityPartitions()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //valid IPv4 addresses range [0.0.0.0, 255.255.255.255]
	   assertTrue("Otherwise valid address with min valid IPv4 host name should be valid", urlVal.isValid("http://0.0.0.0"));
	   assertTrue("Otherwise valid address with max valid IPv4 host name should be valid", urlVal.isValid("http://255.255.255.255"));
	   //invalid IPv4 addresses range [INT_MIN.INT_MIN.INT_MIN.INT_MIN, 0.0.0.-1]
	   assertFalse("Otherwise valid address with min negative invalid IPv4 host name should be invalid", 
			   urlVal.isValid("http://" + (int)Integer.MIN_VALUE + (int)Integer.MIN_VALUE + (int)Integer.MIN_VALUE + (int)Integer.MIN_VALUE));
	   assertFalse("Otherwise valid address with max negative invalid IPv4 host name should be invalid", urlVal.isValid("http://0.0.0.-1"));
	   //invalid IPv4 addresses range [255.255.255.256, INT_MAX.INT_MAX.INT_MAX.INT_MAX]
	   assertFalse("Otherwise valid address with min postive invalid IPv4 host name should be invalid", urlVal.isValid("http://255.255.255.256"));
	   assertFalse("Otherwise valid address with max positive invalid IPv4 host name should be invalid", 
			   urlVal.isValid("http://" + (int)Integer.MAX_VALUE + (int)Integer.MAX_VALUE + (int)Integer.MAX_VALUE + (int)Integer.MAX_VALUE));
	   //min and max lowercase letter and number reg-names
	   assertTrue("Otherwise valid address with valid min lowercase0 (a) reg-name should be valid", urlVal.isValid("http://a"));
	   assertTrue("Otherwise valid address with valid max lowercase (z) reg-name should be valid", urlVal.isValid("http://z"));
	   assertTrue("Otherwise valid address with valid min number (0) reg-name should be valid", urlVal.isValid("http://0"));
	   assertTrue("Otherwise valid address with valid max number (9) reg-name should be valid", urlVal.isValid("http://9"));
	   //min and max reg-name lengths [1,253]
	   assertTrue("Otherwise valid address with min length (1) reg-name should be valid", urlVal.isValid("http://1"));
	   String s = "http://";
	   for(int i = 0; i < 11; i++) {
		  for(int j = 0; j < 22; j++) {
			  s += "a";
		  }
		  s += ".";
	   }
	   assertTrue("Otherwise valid address with max length (253) reg-name should be valid", urlVal.isValid(s));
	   //invalid length reg-names
	   assertFalse("Otherwise valid address with min invalid positive length (254) reg-name should be invalid", urlVal.isValid(s + "a"));
	   assertFalse("Otherwise valid address with 0 length reg-name should be invalid", urlVal.isValid("http://"));
	   //test valid and invalid positions for '-'
	   assertTrue("Otherwise valid address with '-' in between numbers or letters in a label of a reg-name should be valid", urlVal.isValid("http://a.a-3.c"));
	   assertFalse("Otherwise valid address with '-' beginning a label of a reg-name should be invalid", urlVal.isValid("http://-a"));
	   assertFalse("Otherwise valid address with '-' ending a label of a reg-name should be invalid", urlVal.isValid("http://a-"));

   }
   
   //Valid ports in the range 0-65535 - https://en.wikipedia.org/wiki/Port_(computer_networking) tested with three partitions: [INT_MIN, -1], [0,65535], [65536, INT_MAX]
   public void testPortPartitions()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //sample base valid address
	   assertTrue("Sample base valid address http://www.google.com should be valid.", urlVal.isValid("http://www.google.com"));
	   //min and max values in valid range [0, 65535]
	   assertTrue("Otherwise valid address with a minimum valid port number (0) should be valid", urlVal.isValid("http://www.google.com:0"));
	   assertTrue("Otherwise valid address with a maximum valid port number (65535) should be valid", urlVal.isValid("http://www.google.com:65535"));
	   //min and max values in negative range [INT_MIN, -1]
	   assertFalse("Otherwise valid address with a minimum invalid negative port number (INT_MIN) should be invalid",
		urlVal.isValid("http://www.google.com:" + (int)Integer.MIN_VALUE));
	   assertFalse("Otherwise valid address with a maximum invalid negative port number (-1) should be invalid", urlVal.isValid("http://www.google.com:-1"));
	   //min and max values in positive range [65536, INT_MAX]
	   assertFalse("Otherwise valid address with a minimum invalid positive port number (65536) should be invalid", urlVal.isValid("http://www.google.com:65536"));
	   assertFalse("Otherwise valid address with a maximum invalid positive port number (INT_MAX) should be invalid", 
		urlVal.isValid("http://www.google.com:" + (int)Integer.MAX_VALUE));

   }
   ResultPair[] testSchemes = {
			   new ResultPair("", true), 
			   new ResultPair("x://", true), 
			   new ResultPair("Y://", true), 
			   new ResultPair("5://", false), 
			   new ResultPair("A0://", true), 
			   new ResultPair("c4://", true), 
			   new ResultPair("C+://", true), 
			   new ResultPair("r-://", true), 
			   new ResultPair("o.://", true), 
			   new ResultPair("1q://", false), 
			   new ResultPair("2H://", false), 
			   new ResultPair("3+://", false), 
			   new ResultPair("4-://", false), 
			   new ResultPair("9.://", false),
			   new ResultPair("gG://", true), 
			   new ResultPair("Rr://", true), 
			   new ResultPair("oO.://", true), 
			   new ResultPair("Yy+://", true), 
			   new ResultPair("DdD-://", true),
			   new ResultPair("Y12a+://", true), 
			   new ResultPair("o1j-://", true), 
			   new ResultPair("R5.://", true)
			   };
	   String maxAuth = "";
	   for(int i = 0; i < 10; i++){
		   maxAuth += "abcdEFGH104abcdEFGH104.";
	   }
	   ResultPair[] testAuthorities = {
			   new ResultPair("0.0.0.0", true), 
			   new ResultPair("255.255.255.255", true), 
			   new ResultPair("255.255.255.256", false), 
			   new ResultPair("0.0.0.-1", false), 
			   new ResultPair("0.0.0.0", true), 
			   new ResultPair("b", true), 
			   new ResultPair("R", true), 
			   new ResultPair("6", true),
			   new ResultPair(maxAuth, true),
			   new ResultPair(maxAuth + "4", false),
			   new ResultPair("R-", true),
			   new ResultPair("-R", false),
			   new ResultPair("c.", true), 
			   new ResultPair(".c", false),
			   new ResultPair("3.A.b", true),
			   new ResultPair("e.F.0", true),
			   new ResultPair("A-9.r", true),
			   new ResultPair("A..r", false),
			   new ResultPair("e..6", false),
			   };
	   
	   ResultPair[] testPorts = {
			   new ResultPair("6", true),
			   new ResultPair("50", true),
			   new ResultPair("1284", true),
			   new ResultPair("61249", true),
			   new ResultPair("-3", false),
			   new ResultPair("-89", false),
			   new ResultPair("-3463", false),
			   new ResultPair("-10826", false),
			   new ResultPair("-83378", false),
			   new ResultPair("69123", false),
			   new ResultPair("123382", false)
			   };
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
}
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   



//ResultPair[] testPath = {new ResultPair("/test1", true),
//   new ResultPair("/t123", true),
//   new ResultPair("/$23", true),
//   new ResultPair("/..", false),
//   new ResultPair("/../", false),
//   new ResultPair("/test1/", true),
//   new ResultPair("", true),
//   new ResultPair("/test1/file", true),
//   new ResultPair("/..//file", false),
//   new ResultPair("/test1//file", false)
//};
////Test allow2slash, noFragment
//ResultPair[] testUrlPathOptions = {new ResultPair("/test1", true),
//             new ResultPair("/t123", true),
//             new ResultPair("/$23", true),
//             new ResultPair("/..", false),
//             new ResultPair("/../", false),
//             new ResultPair("/test1/", true),
//             new ResultPair("/#", false),
//             new ResultPair("", true),
//             new ResultPair("/test1/file", true),
//             new ResultPair("/t123/file", true),
//             new ResultPair("/$23/file", true),
//             new ResultPair("/../file", false),
//             new ResultPair("/..//file", false),
//             new ResultPair("/test1//file", true),
//             new ResultPair("/#/file", false)
//};
//
//ResultPair[] testUrlQuery = {new ResultPair("?action=view", true),
//       new ResultPair("?action=edit&mode=up", true),
//       new ResultPair("", true)
//};
//
//Object[] testUrlParts = {testUrlScheme, testUrlAuthority, testUrlPort, testPath, testUrlQuery};
//Object[] testUrlPartsOptions = {testUrlScheme, testUrlAuthority, testUrlPort, testUrlPathOptions, testUrlQuery};
//int[] testPartsIndex = {0, 0, 0, 0, 0};
//
////---------------- Test data for individual url parts ----------------
//ResultPair[] testScheme = {new ResultPair("http", true),
//     new ResultPair("ftp", false),
//     new ResultPair("httpd", false),
//     new ResultPair("telnet", false)
//
