VInt Matrix3::getVectorAtLine(const unsigned& lineNum) const
{
    VInt vec(matrix.size(), 0);
    for(shared_ptr<CNode<pairColVal>> ptr(matrix[lineNum].fictionalHead()->getNextNode()); ptr != matrix[lineNum].fictionalTail();
        ptr = ptr->getNextNode())
            vec[ptr->getData().first] = ptr->getData().second;

    return vec;
}

VInt Matrix3::getVectorAtCol(const unsigned& colNum) const
{
    VInt vec(matrix.size(), 0);
    for(unsigned i(0); i < matrix.size(); ++i)
    {
        for(shared_ptr<CNode<pairColVal>> ptr(matrix[i].fictionalHead()->getNextNode());
            ptr != matrix[i].fictionalTail() && ptr->getData().first <= colNum;
            ptr = ptr->getNextNode())
        {
            if(ptr->getData().first == colNum)
                vec[i] = ptr->getData().second;
        }
    }
    return vec;
}

int Matrix3::getValue(const unsigned& lineNum, const unsigned& colNum) const
{
    for(shared_ptr<CNode<pairColVal>> ptr(matrix[lineNum].fictionalHead()->getNextNode()); ptr != matrix[lineNum].fictionalTail() && ptr->getData().first <= colNum; ptr = ptr->getNextNode())
        if(ptr->getData().first == colNum)
            return ptr->getData().second;

    return 0;
}
