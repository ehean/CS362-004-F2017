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
