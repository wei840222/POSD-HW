# POSD2017F Homework

## Homework assignment 4

Please use [the files that were used in course](https://github.com/yccheng66/posd2017f) and copy test header to your repository from this project.

:zap: Some people will place header files into `include` folder, and it may cause the building of .ut job to fail. If so, just email to us and we will change the configuation for you.

#### Update

 * Mon Oct 23 2017 09:54:36
 
   * Please check your ut job, if it's passed but there is no test report comes out (besides first time building), it means your progarm actually is crash. We are discussing about this cas and think about how to fix it or is there other solution. 
   
   * And about test case X = [496, X, terence_tao]. In this weekend, we replied one student that this decision was a sample judgment that we made and it can be corrected if it's wrong truly. But it sounds pretty irresponsible(sorry for Mr. X), so we re-discuss this case today.\
      \
      About this metter, we need to check the definition of matching. In the section 2.2 *Matching* of the book: PROLOG Programming for Artificial Intelligence (third version, Ivan Bratko, 0-201-40375-7), said if two terms match, it must: (1)They are identical, or (2) the variables in both terms can be instantiated to objects in such a way that after the substitution of variables by these objects the terms become identical. Rule (1) is easy to understand, but what is rule (2)? Rule (2) means that if it can get the any value which can make the equation holds, we said it match. For our case, if variable X could be instantiated by any value that make the equation holds, the #match() should return true, otherwise returns false. **But it couldn't be, and also not yet.**\
      \
      We can't set true or false on this case utill the variable X can be instantiated. In SWI-Prolog you will get the string "X = [496, X, terence_tao]" as the result instead of false, but it doesn't mean that this matching actually returns true or false(in program). So, for this one, **we just decided to make it not score. You can get the points but you still need to write the test, we don't care about the true or false it returns.**
   
#### Assignment requirement

  1.  Implement `List` according to the `list.h`, and also all tests in `utList.h`.

  2. Write the corresponding makefile to generate executable file which named `hw4`. Note that it is the executable name, not the test file name.

  3. Make sure your CI jobs are both passed before deadline.

#### Marks

  You totally have 19 tests in your own, each one is 2 points.
  And TA's test also have 19 tests, each one is 3 points.
  The sum of this homework is 95 points.

#### Deadline

  Friday Oct 27 2017 23:59:59

#### Note

  * About project structure. In pervious homework, some people will place test file into folder and write the corresponding makefile. (e.g. `variable.h` in *include* folder ) This will result the executable in .ut job that still contains your test script but not ours because we just replace the test file at root directory. Thus, the report of test result shows all tests are passed, but in the fact it may isn't. So, if you place your files into some folder, please check the test report in .ut job that test script is still yours or not.
  
    **Just email us if you have that situation.**

  * Try to read building information in console log and fix the hw problem  by yourself as possible as you can.
  
  * If your CI job can not pull your repository, email to us.

#### Change log

  * Sun Oct 22 2017 13:45:41
  
    The description on test `Numbers` is wrong, there should be two numbers. Please modify your test if there is only one.
    
    ```diff
    + // Given there are two perfect Numbers: 8128, 496
    + // When create a new list with the perfect Number
    + // Then #symbol() of the list should return "[8128, 496]"
    - // Given there are two perfect Numbers: 8128
    - // When create a new list with the perfect Number
    - // Then #symbol() of the list should return "[8128]"
    ```
  
  * Sat Oct 21 2017 11:12:56

    The description on test `headAndTailMatching3` is wrong, the H should return *[first]* and the T returns *[second, third]*.

    ```diff
    + // ?- [[first], second, third] = [H|T].
    + // H = [first], T = [second, third].
    - // ?- [[first], second, third] = [H|T].
    - // H = first, T = [[second], third].
    ```
  
