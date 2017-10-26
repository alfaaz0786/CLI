import java.io.*;

class DecisionTreeApp
{

   
    static BufferedReader keyboardInput = new BufferedReader(new InputStreamReader(System.in));
    static DecisionTree newTree;

    public static void main(String[] args) throws IOException
    {

        newTree = new DecisionTree();

        generateTree();

        System.out.println("\nOUTPUT DECISION TREE");
        System.out.println("====================");
        newTree.outputBinTree();
		queryTree();
     }

   

    static void generateTree() 
    {
         System.out.println("\nGENERATE DECISION TREE");
        System.out.println("======================");
        newTree.createRoot(1,"Semisterwise Computer Branch Subject");
        newTree.addYesNode(1,2,"Semister-1?");
        newTree.addNoNode(1,3,"Semister-2?");
        newTree.addYesNode(2,4,"Elective");
        newTree.addYesNode(4,8," Subject is DMT");
        newTree.addNoNode(4,9,"Subject is PC");
        newTree.addNoNode(2,5,"Compulsory Subject");
        newTree.addYesNode(5,10,"Subject is PMCD");
        newTree.addNoNode(5,11,"Subject is DAA");

        newTree.addYesNode(3,6,"Elective");
        newTree.addYesNode(6,12,"Elective-1");
        newTree.addNoNode(6,13,"Elective-2");

        newTree.addNoNode(3,7,"Compulsory Subject");
        newTree.addYesNode(7,14,"Subject is SDMT");
        newTree.addNoNode(7,15,"Subject is HPC");
    }

	
    static void queryTree() throws IOException
    {
        System.out.println("\nQUERY DECISION TREE");
        System.out.println("===================");
        newTree.queryBinTree();
        optionToExit();
     }

    static void optionToExit() throws IOException
    {
        System.out.println("Exit? (enter \"Yes\" or \"No\")");
        String answer = keyboardInput.readLine();
        if (answer.equals("Yes"))
		 return;
        else
	   {
            if (answer.equals("No"))
				 queryTree();
            else
		  {
                System.out.println("ERROR: Must answer \"Yes\" or \"No\"");
                optionToExit();
             }
         }
      }
}


class DecisionTree
{

   

    private class BinTree
    {
		private int     nodeID;
	    	private String  questOrAns = null;
	    	private BinTree yesBranch  = null;
	    	private BinTree noBranch   = null;

		public BinTree(int newNodeID, String newQuestAns)
     	{
		    nodeID     = newNodeID;
		    questOrAns = newQuestAns;
		}
	}

  

    static BufferedReader    keyboardInput = new BufferedReader(new InputStreamReader(System.in));
    BinTree rootNode = null;

    public DecisionTree() {  }

    public void createRoot(int newNodeID, String newQuestAns)
    {
	    rootNode = new BinTree(newNodeID,newQuestAns);	
	    System.out.println("Created root node " + newNodeID);	
    }
			


    public void addYesNode(int existingNodeID, int newNodeID, String newQuestAns)
    {
	
	
		if (rootNode == null)
		{
		    System.out.println("ERROR: No root node!");
		    return;
		 }
	
		// Search tree
	
		if (searchTreeAndAddYesNode(rootNode,existingNodeID,newNodeID,newQuestAns))
		{
		    		System.out.println("Added node " + newNodeID + " onto \"yes\" branch of node " + existingNodeID);
		}
		else System.out.println("Node " + existingNodeID + " not found");
	}

    /* SEARCH TREE AND ADD YES NODE */

    private boolean searchTreeAndAddYesNode(BinTree currentNode,int existingNodeID, int newNodeID, String newQuestAns) 
    {
	    	if (currentNode.nodeID == existingNodeID) 
		{
		    // Found node
		    if (currentNode.yesBranch == null)
				currentNode.yesBranch = new BinTree(newNodeID,newQuestAns);
		    else
		    {
			    System.out.println("WARNING: Overwriting previous node " + "(id = " + currentNode.yesBranch.nodeID +") linked to yes branch of node " + existingNodeID);
			currentNode.yesBranch = new BinTree(newNodeID,newQuestAns);
			}		
	    	    return(true);
		 }
		 else 
           {
		    // Try yes branch if it exists
			    if (currentNode.yesBranch != null)
		         { 	
				    if (searchTreeAndAddYesNode(currentNode.yesBranch,existingNodeID,newNodeID,newQuestAns))
		               {    	
					  return(true);
					}	
					else 
					{
			    	        // Try no branch if it exists
				    	    if (currentNode.noBranch != null) 
						{
			    	    			return(searchTreeAndAddYesNode(currentNode.noBranch,existingNodeID,newNodeID,newQuestAns));
						}
					    	else return(false);	// Not found here
					 }
		    		}
			    	return(false);		// Not found here
		  }
   	} 	
    		
    /* ADD NO NODE */

    public void addNoNode(int existingNodeID, int newNodeID, String newQuestAns)
	{
	// If no root node do nothing
	
		if (rootNode == null)
		{
		    System.out.println("ERROR: No root node!");
		    return;
	    	}
	
	// Search tree
	
		if (searchTreeAndAddNoNode(rootNode,existingNodeID,newNodeID,newQuestAns))
		{
	   		 System.out.println("Added node " + newNodeID +" onto \"no\" branch of node " + existingNodeID);
	    	}
		else System.out.println("Node " + existingNodeID + " not found");
	}
	
    /* SEARCH TREE AND ADD NO NODE */

    private boolean searchTreeAndAddNoNode(BinTree currentNode, int existingNodeID, int newNodeID, String newQuestAns)
	{
    		if (currentNode.nodeID == existingNodeID)
		{
	    // Found node
		    	   if (currentNode.noBranch == null) currentNode.noBranch = new BinTree(newNodeID,newQuestAns);
			   else
		        {
			   System.out.println("WARNING: Overwriting previous node " + "(id = " + currentNode.noBranch.nodeID + ") linked to yes branch of node " + existingNodeID);
				currentNode.noBranch = new BinTree(newNodeID,newQuestAns);
			   }  		
	    	    return(true);
	    }
	   else
        {
	    // Try yes branch if it exists
	     if (currentNode.yesBranch != null)
          { 	
	        if (searchTreeAndAddNoNode(currentNode.yesBranch,existingNodeID,newNodeID,newQuestAns))
		   {    	
	            return(true);
		    }	
		   else
             {
    	        // Try no branch if it exists
		    	    if (currentNode.noBranch != null)
		         {
	    	    		return(searchTreeAndAddNoNode(currentNode.noBranch,existingNodeID,newNodeID,newQuestAns));
				}
				else return(false);	// Not found here
		    }
		 }
	      else return(false);	// Not found here
	    }
   	} 	



    public void queryBinTree() throws IOException
    {
        queryBinTree(rootNode);
    }

    private void queryBinTree(BinTree currentNode) throws IOException
    {

        // Test for leaf node (answer) and missing branches

        if (currentNode.yesBranch==null)
         {
            if (currentNode.noBranch==null)
				System.out.println(currentNode.questOrAns);
            else 
			System.out.println("Error: Missing \"Yes\" branch at \"" + currentNode.questOrAns + "\" question");
           
		  return;
          }
          if (currentNode.noBranch==null)
		{
            System.out.println("Error: Missing \"No\" branch at \"" + currentNode.questOrAns + "\" question");
            return;
          }

        // Question

         askQuestion(currentNode);
     }

    private void askQuestion(BinTree currentNode) throws IOException
    {
        System.out.println(currentNode.questOrAns + " (enter \"Yes\" or \"No\")");
        String answer = keyboardInput.readLine();
        if (answer.equals("Yes")) 
			queryBinTree(currentNode.yesBranch);
        else 
	   {
            if (answer.equals("No")) 
				queryBinTree(currentNode.noBranch);
            else
		  {
                System.out.println("ERROR: Must answer \"Yes\" or \"No\"");
                askQuestion(currentNode);
             }
          }
     }

    	public void outputBinTree()
	{

        outputBinTree("1",rootNode);
     }

     private void outputBinTree(String tag, BinTree currentNode)
	{

		   // Check for empty node

		   if (currentNode == null) return;

		   // Output

		   System.out.println("[" + tag + "] nodeID = " + currentNode.nodeID +
		   		", question/answer = " + currentNode.questOrAns);
		   		
		   // Go down yes branch

		   outputBinTree(tag + ".1",currentNode.yesBranch);

		   // Go down no branch

		   outputBinTree(tag + ".2",currentNode.noBranch);
	 }      		
    }



/*OUTPUT:
damini@ubuntu:~$ javac DecisionTreeApp.java
damini@ubuntu:~$ java DecisionTreeApp

GENERATE DECISION TREE
======================
Created root node 1
Added node 2 onto "yes" branch of node 1
Added node 3 onto "no" branch of node 1
Added node 4 onto "yes" branch of node 2
Added node 8 onto "yes" branch of node 4
Added node 9 onto "no" branch of node 4
Added node 5 onto "no" branch of node 2
Added node 10 onto "yes" branch of node 5
Added node 11 onto "no" branch of node 5
Added node 6 onto "yes" branch of node 3
Added node 12 onto "yes" branch of node 6
Added node 13 onto "no" branch of node 6
Added node 7 onto "no" branch of node 3
Added node 14 onto "yes" branch of node 7
Added node 15 onto "no" branch of node 7

OUTPUT DECISION TREE
====================
[1] nodeID = 1, question/answer = Semisterwise Computer Branch Subject
[1.1] nodeID = 2, question/answer = Semister-1?
[1.1.1] nodeID = 4, question/answer = Elective
[1.1.1.1] nodeID = 8, question/answer =  Subject is DMT
[1.1.1.2] nodeID = 9, question/answer = Subject is PC
[1.1.2] nodeID = 5, question/answer = Compulsory Subject
[1.1.2.1] nodeID = 10, question/answer = Subject is PMCD
[1.1.2.2] nodeID = 11, question/answer = Subject is DAA
[1.2] nodeID = 3, question/answer = Semister-2?
[1.2.1] nodeID = 6, question/answer = Elective
[1.2.1.1] nodeID = 12, question/answer = Elective-1
[1.2.1.2] nodeID = 13, question/answer = Elective-2
[1.2.2] nodeID = 7, question/answer = Compulsory Subject
[1.2.2.1] nodeID = 14, question/answer = Subject is SDMT
[1.2.2.2] nodeID = 15, question/answer = Subject is HPC

QUERY DECISION TREE
===================
Semisterwise Computer Branch Subject (enter "Yes" or "No")
Yes
Semister-1? (enter "Yes" or "No")
Yes
Elective (enter "Yes" or "No")
No
Subject is PC
Exit? (enter "Yes" or "No")
No

QUERY DECISION TREE
===================
Semisterwise Computer Branch Subject (enter "Yes" or "No")
No
Semister-2? (enter "Yes" or "No")
No
Compulsory Subject (enter "Yes" or "No")
No
Subject is HPC
Exit? (enter "Yes" or "No")
Yes
damini@ubuntu:~$ 

