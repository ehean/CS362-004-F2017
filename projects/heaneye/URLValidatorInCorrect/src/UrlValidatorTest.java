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
   }
   
   
   public void testYourFirstPartition()
   {
	   
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
