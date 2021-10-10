void deleteNode(TreeNode **treePtrP, int value)//还没写完
{
	TreeNode *deleteNodePtr = *treePtrP;
	TreeNode *parentNodeOfDeletePtr = NULL;
	TreeNode *substituteNodePtr;
	TreeNode *parentNodeOfSubstitutePtr;

	while (deleteNodePtr != NULL && value != deleteNodePtr->data)
	{
		parentNodeOfDeletePtr = deleteNodePtr;

		if (deleteNodePtr->data > value)
		{
			deleteNodePtr = deleteNodePtr->leftPtr;
		}
		else
		{
			deleteNodePtr = deleteNodePtr->rightPtr;
		}
	}

	if (deleteNodePtr == NULL)
	{
		printf("no such Node, delete fail\n\n");
		return;

	}

	if (deleteNodePtr->leftPtr == NULL && deleteNodePtr->rightPtr == NULL)
	{

		if (parentNodeOfDeletePtr == NULL)
		{
			*treePtrP = NULL;
		}
		else if (parentNodeOfDeletePtr->leftPtr == deleteNodePtr)
		{
			parentNodeOfDeletePtr->leftPtr = NULL;
		}
		else
		{
			parentNodeOfDeletePtr->rightPtr = NULL;
		}

	}
	else if (deleteNodePtr->leftPtr != NULL && deleteNodePtr->rightPtr == NULL)
	{
		if (parentNodeOfDeletePtr == NULL)
		{
			*treePtrP = deleteNodePtr->leftPtr;
		}
		else if (parentNodeOfDeletePtr->rightPtr == deleteNodePtr)
			parentNodeOfDeletePtr->rightPtr = deleteNodePtr->leftPtr;
		else
			parentNodeOfDeletePtr->leftPtr = deleteNodePtr->leftPtr;

	}

	else if (deleteNodePtr->leftPtr == NULL && deleteNodePtr->rightPtr != NULL)
	{
		if (parentNodeOfDeletePtr == NULL)
		{
			*treePtrP = deleteNodePtr->rightPtr;
		}
		else if (parentNodeOfDeletePtr->rightPtr == deleteNodePtr)
			parentNodeOfDeletePtr->rightPtr = deleteNodePtr->rightPtr;
		else
			parentNodeOfDeletePtr->leftPtr = deleteNodePtr->rightPtr;

	}
	else
	{
		parentNodeOfSubstitutePtr = deleteNodePtr;
		substituteNodePtr = deleteNodePtr->leftPtr;

		while (substituteNodePtr->rightPtr != NULL)
		{
			parentNodeOfSubstitutePtr = substituteNodePtr;
			substituteNodePtr = substituteNodePtr->rightPtr;

		}

		if (parentNodeOfDeletePtr == NULL)
		{
			*treePtrP = substituteNodePtr;
		}
		else if (parentNodeOfDeletePtr->leftPtr == deleteNodePtr)
		{
			parentNodeOfDeletePtr->leftPtr = substituteNodePtr;
		}
		else
		{
			parentNodeOfDeletePtr->rightPtr = substituteNodePtr;
		}

		substituteNodePtr->rightPtr = deleteNodePtr->rightPtr;

		if (parentNodeOfSubstitutePtr != deleteNodePtr)
		{
			substituteNodePtr->leftPtr = deleteNodePtr->leftPtr;

			if (parentNodeOfSubstitutePtr->leftPtr == substituteNodePtr)
			{
				parentNodeOfSubstitutePtr->leftPtr = substituteNodePtr->leftPtr;
			}
			else
			{
				parentNodeOfSubstitutePtr->rightPtr = substituteNodePtr->leftPtr;
			}
		}
		
	}

	free(deleteNodePtr);
}

