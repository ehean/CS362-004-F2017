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
import java.util.*;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {
	
	
	/* TEST CASE OBJECTS WILL HELP WITH ANALYZING TESTS */
	public class TestCase {
      public Integer number;
      public ResultPair[] resultPairs;
      public Boolean totalPass = true;
      public Boolean schemePass = true,
    		  authorityPass = true, 
    		  portPass = true, 
    		  pathPass = true, 
    		  queryPass = true;

      public TestCase(Integer n, ResultPair[] p) {
         this.number = n;
         this.resultPairs = p;  
      }
      
      public void testCasePass(Boolean p) {
    	  this.totalPass = p;
      }
   }


   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

	//method for asserting the expression actual is equal to the expected expression, printing out the test and whether or not it actually evaluates to true or false
   public void myAssert(String test, Boolean expected, Boolean actual) {
	System.out.println("Testing \"isValid(" + test + ")\" is equal to expected: " + expected + "\n" + "actual: " + actual);
   }
   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
//	   /* MANUAL TEST SCHEMES */
//	   System.out.println("VALID MANUAL TEST SCHEMES");
//	   
//	   /* EXPECTED RESULT: PASS */
//	   System.out.println(urlVal.isValid("http://www.amazon.com"));
//	   System.out.println(urlVal.isValid("https://www.amazon.com"));
//	   System.out.println(urlVal.isValid("h3t://www.amazon.com"));
//	   
//	   // THIS RETURNS A FALSE NEGATIVE
//	   System.out.println(urlVal.isValid("www.amazon.com"));
//	   System.out.println(urlVal.isValid("ftp://www.amazon.com"));
//	   System.out.println(urlVal.isValid("Http://www.amazon.com"));
//	  
//	   
//	   /* EXPECTED RESULT: FAIL */
//	   System.out.println("INVALID MANUAL TEST SCHEMES");
//	   System.out.println(urlVal.isValid("http:/www.amazon.com"));
//	   System.out.println(urlVal.isValid("http:www.amazon.com"));
//	   System.out.println(urlVal.isValid("http//www.amazon.com"));
//	   System.out.println(urlVal.isValid("://www.amazon.com"));
//	   System.out.println(urlVal.isValid("http:\\www.amazon.com"));
//	   
//	   
//	   /* MANUAL TEST AUTHORITY */
//	   
//	   System.out.println("VALID MANUAL TEST PATHS");
//	   
//	   /* EXPECTED RESULT: PASS */
//	   System.out.println(urlVal.isValid("http://amazon.com"));
//	   
//	   /* RETURNS FALSE NEGATIVE */
//	   System.out.println(urlVal.isValid("http://amazon.nz"));
//	   System.out.println(urlVal.isValid("http://0.0.0.0"));
//	   System.out.println(urlVal.isValid("http://255.255.255.255"));
//	   System.out.println(urlVal.isValid("http://128.com"));
//	   System.out.println(urlVal.isValid("http://amazon.gov"));
//	   
//	   /* EXPECTED RESULT: FAIL */
//	   System.out.println("INVALID MANUAL TEST PATHS");
//	   System.out.println(urlVal.isValid("http://amaz/on.com"));
//	   System.out.println(urlVal.isValid("http://amazon.nzs"));
//	   System.out.println(urlVal.isValid("http://0.0.0.-1"));
//	   
//	   /* RETURNS FALSE POSITIVE */
//	   System.out.println(urlVal.isValid("http://255.255.255.256"));
//	   System.out.println(urlVal.isValid("http://128..com"));
//	   System.out.println(urlVal.isValid("http://amaz?on.gov"));
//	   
//	   
//	   /* MANUAL TEST PORT */
//	   
//	   System.out.println("VALID MANUAL TEST PORTS");
//	   
//	   /* EXPECTED RESULT: PASS */
//	   System.out.println(urlVal.isValid("http://www.amazon.com:80"));
//	   
//	   /* RETURNS FALSE NEGATIVE */
//	   System.out.println(urlVal.isValid("http://www.amazon.com:65535"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com:0"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com:034"));
//	   
//	   /* EXPECTED RESULT: FAIL */
//	   System.out.println("INVALID MANUAL TEST PATHS");
//	   System.out.println(urlVal.isValid("http://www.amazon.com:"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com:s"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com:-1"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com;0"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com:09348248"));
//	   
//	  /*Test Paths*/
	   //void path
	   System.out.println("\nMANUAL TESTING PATHS");
	   String test = "http://google.com:80";
	   myAssert(test, true, urlVal.isValid(test));
	   //single valid xpalphas paths
	   test = "http://www.google.com:80/+";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:80/a";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:80/0";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:80/$";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:80/!";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:80/%aa";
	   myAssert(test, true, urlVal.isValid(test));
	   //multiple xpalphas path delimited by forward slashes
	   test = "http://www.google.com:80/+a0$!%aa/+a0$!%aa/+a0$!%aa/";
	   myAssert(test, true, urlVal.isValid(test));
	   //single invalid char paths
	   test = "http://www.google.com:80/{";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://www.google.com:80/<";
	   myAssert(test, false, urlVal.isValid(test));
	   //multiple invalid character paths delimited by forward slashes
	   test = "http://www.google.com:80/{</?{</?{</?{</";
	   myAssert(test, false, urlVal.isValid(test));
	   //one valid character and one invalid character
	   test = "http://www.google.com:80/{a";
	   myAssert(test, false, urlVal.isValid(test));
	   //mixing of invalid characters and invalid character paths delimited by forward slashes
	   test = "http://www.google.com:80/+a0$!%aa?{</+a0$!%aa?{</";
	   myAssert(test, false, urlVal.isValid(test));

	   /*Test Queries*/
	   System.out.println("\nMANUAL TESTING QUERIES");
	   //void query
	   test = "http://www.google.com:80/";
	   myAssert(test, true, urlVal.isValid(test));
	   //? query
	   test = "http://www.google.com:80/?a1+}{!@$%&^*";
	   myAssert(test, true, urlVal.isValid(test));
   }
   
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
//	   /* MANUAL TEST PATHS */
//	   System.out.println("VALID TEST PATHS");
//	   
//	   /* EXPECTED RESULT: PASS */
//	   System.out.println(urlVal.isValid("http://www.amazon.com"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/test"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/123"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/@"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/&"));
//	   
//	   /* NOT SURE WHY '?' RETURNS FALSE */
//	   System.out.println(urlVal.isValid("http://www.amazon.com/?"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/="));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/+"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/,"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/."));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/!"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/~"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/*"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/'"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/%"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/$"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/_"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/;"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/("));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/)"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/test/"));
//	   
//	   
//	   /* MANUAL TEST PATHS */
//	   System.out.println("INVALID TEST PATHS");
//	   
//	   /* EXPECTED RESULT: FAIL */
//	   System.out.println(urlVal.isValid("http://www.amazon.com/\\"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com["));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/]"));
//	   
//	   /* NOT SURE WHY '//' RETURNS FALSE */
//	   System.out.println(urlVal.isValid("http://www.amazon.com//"));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/(("));
//	   System.out.println(urlVal.isValid("http://www.amazon.com/~~"));
//	   
//	   
////	   String tooLong = null;
////	   for (int i = 0; i < Integer.MAX_VALUE; i++) {
////		   tooLong += "a";
////	   }
////	   
////	   
////	   System.out.println(urlVal.isValid("http://www.amazon.com/" + tooLong));
//	   
//	   
//	   
//	   Integer intTest = 1;
//	   System.out.println(urlVal.isValid("http://www.amazon.com/" + intTest));
//	   Boolean boolTest = true;
//	   System.out.println(urlVal.isValid("http://www.amazon.com/" + boolTest));	 
//	   Double floatTest = 1.0;
//	   System.out.println(urlVal.isValid("http://www.amazon.com/" + floatTest));
//	   Character charTest = 'a';
//	   System.out.println(urlVal.isValid("http://www.amazon.com/" + charTest));
//	   
//	   
//	   
//	   /* VALID QUERY TESTS */
//	   System.out.println("VALID QUERY PATHS");
//	   
//	   System.out.println(urlVal.isValid("http://www.amazon.com/test?action=view"));
   }
   
   /*test schemes partitioned by beginning valid letters [a,z], [A,Z], invalid chars above and below these values, ending valid numbers [0,9], letters [a,z], [A,Z],
   invalid chars above and below these values, ., +, and - */
   public void testSchemePartitions()
   {
	   System.out.println("\nTESTING SCHEME PARTITIONS");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //schemes beginning with min and max valid lowercase letters a,z
	   String test = "a://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "z://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //schemes beginning with ASCII chars above and below min and max valid lowercase letters a,z
	   test = "`://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "{://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   //schemes beginning with min and max valid uppercase letters A,Z
	   test = "A://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "Z://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //schemes beginning with ASCII chars above and below min and max valid uppercase letters A,Z
	   test = "@://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "[://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   //schemes ending with min and max valid numbers 0,9 should be valid
	   test = "a0://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "a9://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //schemes beginning with min and max valid numbers 0,9 should be invalid
	   test = "0a://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "9a://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   //schemes ending with min and max valid lowercase letters a,z
	   test = "aa://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "az://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //schemes ending with ASCII chars above and below min and max valid lowercase letters a,z
	   test = "a`://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "a{://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   //schemes ending with min and max valid uppercase letters A,Z
	   test = "aA://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "aZ://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //schemes ending with ASCII chars above and below min and max valid uppercase letters A,Z, should be invalid
	   test = "a@://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "a[://www.google.com";
	   myAssert(test, false, urlVal.isValid(test));
	   //schemes ending with . or + or -
	   test = "a.://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "a+://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "a-://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
   }
   
   //Test authorities in the IPv4 format [0.0.0.0, 255.255.255.255] and reg-name host name format: dot delimited [a,z] [0,9], - https://en.wikipedia.org/wiki/Hostname
   public void testAuthorityPartitions()
   {
	   System.out.println("\nTESTING AUTHORITY PARTITIONS");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //valid IPv4 addresses range [0.0.0.0, 255.255.255.255]
	   String test = "http://0.0.0.0";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://255.255.255.255";
	   myAssert(test, true, urlVal.isValid(test));
	   //invalid IPv4 addresses range [INT_MIN.INT_MIN.INT_MIN.INT_MIN, 0.0.0.-1]
	   test = "http://" + (int)Integer.MIN_VALUE + "." + (int)Integer.MIN_VALUE + "." + (int)Integer.MIN_VALUE + "." + (int)Integer.MIN_VALUE;
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://0.0.0.-1";
	   myAssert(test, false, urlVal.isValid(test));
	   //invalid IPv4 addresses range [255.255.255.256, INT_MAX.INT_MAX.INT_MAX.INT_MAX]
	   test = "http://255.255.255.256";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://" + (int)Integer.MAX_VALUE + "." + (int)Integer.MAX_VALUE + "." + (int)Integer.MAX_VALUE + "." + (int)Integer.MAX_VALUE;
	   myAssert(test, false, urlVal.isValid(test));
	   //min and max lowercase letter and number reg-names
	   test = "http://a";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://z";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://0";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://9";
	   myAssert(test, true, urlVal.isValid(test));
	   //min and max reg-name lengths [1,253]
	   test = "http://a";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://";
	   for(int i = 0; i < 11; i++) {
		  for(int j = 0; j < 22; j++) {
			  test += "a";
		  }
		  test += ".";
	   }
	   myAssert(test, true, urlVal.isValid(test));
	   //invalid length reg-names
	   test += "a";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://";
	   myAssert(test, false, urlVal.isValid(test));
	   //test valid and invalid positions for '-'
	   test = "http://a.a-3.c";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://-a";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://a-";
	   myAssert(test, false, urlVal.isValid(test));
   }
   
   //Valid ports in the range 0-65535 - https://en.wikipedia.org/wiki/Port_(computer_networking) tested with three partitions: [INT_MIN, -1], [0,65535], [65536, INT_MAX]
   public void testPortPartitions()
   {
	   System.out.println("\nTESTING PORT PARTITIONS");
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //sample base valid address
	   String test = "http://www.google.com";
	   myAssert(test, true, urlVal.isValid(test));
	   //min and max values in valid range [0, 65535]
	   test = "http://www.google.com:0";
	   myAssert(test, true, urlVal.isValid(test));
	   test = "http://www.google.com:65535";
	   myAssert(test, true, urlVal.isValid(test));
	   //min and max values in negative range [INT_MIN, -1]
	   test = "http://www.google.com:" + (int)Integer.MIN_VALUE;
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://www.google.com:-1";
	   myAssert(test, false, urlVal.isValid(test));
	   //min and max values in positive range [65536, INT_MAX]
	   test = "http://www.google.com:65536";
	   myAssert(test, false, urlVal.isValid(test));
	   test = "http://www.google.com:" + (int)Integer.MAX_VALUE;
	   myAssert(test, false, urlVal.isValid(test));
   }
  
 
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   ResultPair validScheme = new ResultPair("http://", true);
	   ResultPair validAuthority = new ResultPair("0.0.0.0", true);
	   ResultPair validPort = new ResultPair("6", true);
	   ResultPair validPath = new ResultPair("", true);
	   ResultPair validQuery = new ResultPair("", true);
	   
	   
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
	   
	   ResultPair[] testPaths = {
			   new ResultPair("", true),
			   new ResultPair("/test", true),
			   new ResultPair("/", true),
			   new ResultPair("/1", true),
			   new ResultPair("/@", true),
			   new ResultPair("/&", true),
			   new ResultPair("/?", true),
			   new ResultPair("/=", true),
			   new ResultPair("/+", true),
			   new ResultPair("/,", true),
			   new ResultPair("/.", true),
			   new ResultPair("/!", true),
			   new ResultPair("/~", true),
			   new ResultPair("/*", true),
			   new ResultPair("/'", true),
			   new ResultPair("/%", true),
			   new ResultPair("/$", true),
			   new ResultPair("/_", true),
			   new ResultPair("/;", true),
			   new ResultPair("/(", true),
			   new ResultPair("/)", true),
			   new ResultPair("/test/", true),
			   new ResultPair("\\", false),
			   new ResultPair("/[", false),
			   new ResultPair("/]", false),
			   new ResultPair("//", false),
			   new ResultPair("/((", false),
			   new ResultPair("/~~", false),
			   };
	   
	   ResultPair[] testQueries = {
			   new ResultPair("", true),
			   new ResultPair("?action=view", true),
			   new ResultPair("?", true),
			   new ResultPair("?test", true),
			   new ResultPair("?action=view&more=test", true),
			   new ResultPair("test", false),
			   };
	   

//	   /* VALID QUERY TESTS */
//	   System.out.println("VALID QUERY PATHS");
//	   
//	   System.out.println(urlVal.isValid("http://www.amazon.com/test?action=view"));
	   
	   /* CREATE SETS TO CONTAIN FAILING RESULT PAIRS, 
	    * WHICH WILL HELP WITH TESTING ANALYSIS
	    */
	   
	   int passed = 0, failed = 0;
	   int testCaseIndex = 0;
	   List<TestCase> testSuite = new ArrayList<TestCase>();
	   
	   for(int i = 0; i < testSchemes.length; i++) {
		   for(int j = 0; j < testAuthorities.length; j++) {
			   for(int k = 0; k < testPorts.length; k++) {
				   for(int l = 0; l < testPaths.length; l++) {
					   for(int m = 0; m < testQueries.length; m++) {
						   
						   /* CREATE NEW TEST CASE OBJECT */
						   ResultPair[] resultPairs = {
								   testSchemes[i],
								   testAuthorities[j],
								   testPorts[k],
								   testPaths[l],
								   testQueries[m]
						   };
						   TestCase testcase = new TestCase(testCaseIndex, resultPairs);
						   
						   /* PERFORM TEST */
						   Boolean expected = testSchemes[i].valid && testAuthorities[j].valid && testPorts[k].valid && testPaths[l].valid && testQueries[m].valid;
						   // System.out.println("Testing: " + testSchemes[i].item + testAuthorities[j].item + testPorts[k].item + testPaths[l].item + testQueries[m].item);
						   boolean result = expected == urlVal.isValid(testSchemes[i].item + testAuthorities[j].item + testPorts[k].item + testPaths[l].item + testQueries[m].item);
						   testcase.totalPass = result;
						   if(result) {
							   passed++;
						   }else {
							   failed++;
							   
							   /* TEST EACH FRAGMENT AGAINST CONTROL, RECORD ANY INDEPENDENT FAILURES */
							   
							   /* SCHEME */
							   expected = testSchemes[i].valid && validAuthority.valid && validPort.valid && validPath.valid && validQuery.valid;
							   testcase.schemePass = expected == urlVal.isValid(testSchemes[i].item + validAuthority.item + validPort.item + validPath.item + validQuery.item);
							   
							   /* AUTHORITY */
							   expected = validScheme.valid && testAuthorities[j].valid && validPort.valid && validPath.valid && validQuery.valid;
							   testcase.authorityPass = expected == urlVal.isValid(validScheme.item + testAuthorities[j].item + validPort.item + validPath.item + validQuery.item);
							   
							   /* PORT */
							   expected = validScheme.valid && validAuthority.valid && testPorts[k].valid && validPath.valid && validQuery.valid;
							   testcase.portPass = expected == urlVal.isValid(validScheme.item + validAuthority.item + testPorts[k].item + validPath.item + validQuery.item);
							   
							   /* PATH */
							   expected = validScheme.valid && validAuthority.valid && validPort.valid && testPaths[l].valid && validQuery.valid;
							   testcase.pathPass = expected == urlVal.isValid(validScheme.item + validAuthority.item + validPort.item + testPaths[l].item + validQuery.item);
							   
							   /* QUERY */
							   expected = validScheme.valid && validAuthority.valid && validPort.valid && validPath.valid && testQueries[m].valid;
							   testcase.queryPass = expected == urlVal.isValid(validScheme.item + validAuthority.item + validPort.item + validPath.item + testQueries[m].item);
							   
						   }
						   
						   testSuite.add(testcase);
						   testCaseIndex++;
						   // System.out.println(result);
						   
					   }
				   }
			   }
		   }
	   }
	   System.out.println("Total Failed = " + failed + "\nTotal Passed = " + passed + "\n");
	   
	   
	   int totalAuthorityFailures = 0;
	   int totalSchemeFailures = 0;
	   int totalPortFailures = 0;
	   int totalPathFailures = 0;
	   int totalQueryFailures = 0;

	   
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (!testSuite.get(i).schemePass) {
			   totalSchemeFailures++;
		   }
		   if (!testSuite.get(i).authorityPass) {
			   totalAuthorityFailures++;
		   }
		   if (!testSuite.get(i).portPass) {
			   totalPortFailures++;
		   }
		   if (!testSuite.get(i).pathPass) {
			   totalPathFailures++;
		   }
		   if (!testSuite.get(i).queryPass) {
			   totalQueryFailures++;
		   }
	   }
	   
	   System.out.println("SCHEME FAILURES:");	
	   System.out.println(totalSchemeFailures + "\n");
	   
	   System.out.println("AUTHORITY FAILURES:");	   
	   System.out.println(totalAuthorityFailures + "\n");
	   
	   System.out.println("PORT FAILURES:");	   
	   System.out.println(totalPortFailures + "\n");
	   
	   System.out.println("PATH FAILURES:");	   
	   System.out.println(totalPathFailures + "\n");
	   
	   System.out.println("Query FAILURES:");	   
	   System.out.println(totalQueryFailures + "\n");
	   
	   
	   
	  
	   
	  
	   /* CREATE SETS */
	   Set<ResultPair> failedAuthorityTestCases = new HashSet<ResultPair>();
	   Set<ResultPair> passedAuthorityTestCases = new HashSet<ResultPair>();
	   
	   Set<ResultPair> failedSchemeTestCases = new HashSet<ResultPair>();
	   Set<ResultPair> passedSchemeTestCases = new HashSet<ResultPair>();
	   
	   Set<ResultPair> failedPortTestCases = new HashSet<ResultPair>();
	   Set<ResultPair> passedPortTestCases = new HashSet<ResultPair>();
	   
	   Set<ResultPair> failedPathTestCases = new HashSet<ResultPair>();
	   Set<ResultPair> passedPathTestCases = new HashSet<ResultPair>();
	   
	   Set<ResultPair> failedQueryTestCases = new HashSet<ResultPair>();
	   Set<ResultPair> passedQueryTestCases = new HashSet<ResultPair>();
	   
	   
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedSchemeTestCases.add(testSuite.get(i).resultPairs[0]);
			   passedAuthorityTestCases.add(testSuite.get(i).resultPairs[1]);
			   passedPortTestCases.add(testSuite.get(i).resultPairs[2]);
			   passedPathTestCases.add(testSuite.get(i).resultPairs[3]);
			   passedQueryTestCases.add(testSuite.get(i).resultPairs[4]);
		   }
		   else {
			   if (!testSuite.get(i).schemePass) {
				   failedSchemeTestCases.add(testSuite.get(i).resultPairs[0]);
			   }
			   if (!testSuite.get(i).authorityPass) {
				   failedAuthorityTestCases.add(testSuite.get(i).resultPairs[1]);
			   }
			   if (!testSuite.get(i).portPass) {
				   failedPortTestCases.add(testSuite.get(i).resultPairs[2]);
			   }
			   if (!testSuite.get(i).pathPass) {
				   failedPathTestCases.add(testSuite.get(i).resultPairs[3]);
			   }
			   if (!testSuite.get(i).queryPass) {
				   failedQueryTestCases.add(testSuite.get(i).resultPairs[4]);
			   }
		   }
	   }
	   
	   /* SCHEME TEST SUITE ANALYSIS */
	   System.out.println("SCHEMES");
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedSchemeTestCases.add(testSuite.get(i).resultPairs[0]);
		   }
		   else {
			   if (!testSuite.get(i).schemePass) {
				   failedSchemeTestCases.add(testSuite.get(i).resultPairs[0]);
			   }
		   }
	   }
	   
	   
	   Set<ResultPair> intersectionSchemeTestCases = new HashSet<ResultPair>(failedSchemeTestCases);
	   intersectionSchemeTestCases.retainAll(passedPathTestCases);
	   
	   System.out.println("\n\tINTERSECTION OF PASSED/FAILED SCHEMES");
	   for (ResultPair pair : intersectionSchemeTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   Set<ResultPair> purePassSchemeTestCases = new HashSet<ResultPair>(passedSchemeTestCases);
	   purePassSchemeTestCases.removeAll(failedSchemeTestCases);
	   
	   System.out.println("\n\tALWAYS PASS SCHEMES");
	   for (ResultPair pair : purePassSchemeTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   Set<ResultPair> pureFailSchemeTestCases = new HashSet<ResultPair>(failedSchemeTestCases);
	   pureFailSchemeTestCases.removeAll(passedSchemeTestCases);
	   
	   System.out.println("\n\tALWAYS FAIL SCHEMES");
	   for (ResultPair pair : pureFailSchemeTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   /* AUTHORITY TEST SUITE ANALYSIS */
	   System.out.println("AUTHORITIES");
	   
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedAuthorityTestCases.add(testSuite.get(i).resultPairs[1]);
		   }
		   else {
			   if (!testSuite.get(i).authorityPass) {
				   failedAuthorityTestCases.add(testSuite.get(i).resultPairs[1]);
			   }
		   }
	   }
	   
	   Set<ResultPair> intersectionAuthorityTestCases = new HashSet<ResultPair>(failedAuthorityTestCases);
	   intersectionAuthorityTestCases.retainAll(passedAuthorityTestCases);
	   
	   System.out.println("\n\tINTERSECTION OF PASSED/FAILED AUTHORITIES");
	   for (ResultPair pair : intersectionAuthorityTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   Set<ResultPair> purePassAuthorityTestCases = new HashSet<ResultPair>(passedAuthorityTestCases);
	   purePassAuthorityTestCases.removeAll(failedAuthorityTestCases);
	   
	   System.out.println("\n\tALWAYS PASS AUTHORITIES");
	   for (ResultPair pair : purePassAuthorityTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   Set<ResultPair> pureFailAuthorityTestCases = new HashSet<ResultPair>(failedAuthorityTestCases);
	   pureFailAuthorityTestCases.removeAll(passedAuthorityTestCases);
	   
	   System.out.println("\n\tALWAYS FAIL AUTHORITIES");
	   for (ResultPair pair : pureFailAuthorityTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   /* PORT TEST SUITE ANALYSIS */
	   System.out.println("PORTS");
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedPortTestCases.add(testSuite.get(i).resultPairs[2]);
		   }
		   else {
			   if (!testSuite.get(i).portPass) {
				   failedPortTestCases.add(testSuite.get(i).resultPairs[2]);
			   }
		   }
	   }
	   
	   Set<ResultPair> intersectionPortTestCases = new HashSet<ResultPair>(failedPortTestCases);
	   intersectionPortTestCases.retainAll(passedPortTestCases);
	   
	   System.out.println("\n\tINTERSECTION OF PASSED/FAILED PORTS");
	   for (ResultPair pair : intersectionPortTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   Set<ResultPair> purePassPortTestCases = new HashSet<ResultPair>(passedPortTestCases);
	   purePassPortTestCases.removeAll(failedPortTestCases);
	   
	   System.out.println("\n\tALWAYS PASS PORTS");
	   for (ResultPair pair : purePassPortTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   Set<ResultPair> pureFailPortTestCases = new HashSet<ResultPair>(failedPortTestCases);
	   pureFailPortTestCases.removeAll(passedPortTestCases);
	   
	   System.out.println("\n\tALWAYS FAIL PORTS");
	   for (ResultPair pair : pureFailPortTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   /* PATH TEST SUITE ANALYSIS */
	   System.out.println("PATHS");
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedPathTestCases.add(testSuite.get(i).resultPairs[3]);
		   }
		   else {
			   if (!testSuite.get(i).pathPass) {
				   failedPathTestCases.add(testSuite.get(i).resultPairs[3]);
			   }
		   }
	   }
	   
	   Set<ResultPair> intersectionPathTestCases = new HashSet<ResultPair>(failedPathTestCases);
	   intersectionPathTestCases.retainAll(passedPathTestCases);
	   
	   System.out.println("\n\tINTERSECTION OF PASSED/FAILED PATHS");
	   for (ResultPair pair : intersectionPathTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   Set<ResultPair> purePassPathTestCases = new HashSet<ResultPair>(passedPathTestCases);
	   purePassPathTestCases.removeAll(failedPathTestCases);
	   
	   System.out.println("\n\tALWAYS PASS PATHS");
	   for (ResultPair pair : purePassPathTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   Set<ResultPair> pureFailPathTestCases = new HashSet<ResultPair>(failedPathTestCases);
	   pureFailPathTestCases.removeAll(passedPathTestCases);
	   
	   System.out.println("\n\tALWAYS FAIL PATHS");
	   for (ResultPair pair : pureFailPathTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   /* QUERY TEST SUITE ANALYSIS */
	   System.out.println("QUERIES");
	   for (int i = 0; i < testSuite.size(); i++) {
		   if (testSuite.get(i).totalPass) {
			   passedQueryTestCases.add(testSuite.get(i).resultPairs[4]);
		   }
		   else {
			   if (!testSuite.get(i).queryPass) {
				   failedQueryTestCases.add(testSuite.get(i).resultPairs[4]);
			   }
		   }
	   }
	   
	   Set<ResultPair> intersectionQueryTestCases = new HashSet<ResultPair>(failedQueryTestCases);
	   intersectionQueryTestCases.retainAll(passedQueryTestCases);
	   
	   System.out.println("\n\tINTERSECTION OF PASSED/FAILED QUERIES");
	   for (ResultPair pair : intersectionQueryTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   Set<ResultPair> purePassQueryTestCases = new HashSet<ResultPair>(passedQueryTestCases);
	   purePassQueryTestCases.removeAll(failedQueryTestCases);
	   
	   System.out.println("\n\tALWAYS PASS QUERIES");
	   for (ResultPair pair : purePassQueryTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
	   Set<ResultPair> pureFailQueryTestCases = new HashSet<ResultPair>(failedQueryTestCases);
	   pureFailQueryTestCases.removeAll(passedQueryTestCases);
	   
	   System.out.println("\n\tALWAYS FAIL QUERIES");
	   for (ResultPair pair : pureFailQueryTestCases) {
		   System.out.println("\t\t" + pair.item);
	   }
	   
	   
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
