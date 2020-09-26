VInt Matrix2::getVectorAtLine(const unsigned& lineNum) const
{
    VInt vec(_size, 0);
    for(shared_ptr<CNode<triplet>> ptr(matrix.fictionalHead()->getNextNode());
        ptr != matrix.fictionalTail() && ptr->getData().linenum <= line;
        ptr = ptr->getNextNode())
    {
        if(ptr->getData().liNenum == lineNum)
            vec[ptr->getData().colNum] = ptr->getData().val;
    }
    return vec;
}

VInt Matrix2::getVectorAtCol(const unsigned& colNum) const
{
    VInt vec(_size, 0);
    for(shared_ptr<CNode<triplet>> ptr(matrix.fictionalHead()->getNextNode());
        ptr != matrix.fictionalTail();
        ptr = ptr->getNextNode())
    {
        if(ptr->getData().colNum == colNum)
            vec[ptr->getData().lineNum] = ptr->getData().val;
    }
    return vec;
}

int Matrix2::getValue(const unsigned& lineNum, const unsigned& colNum) const
{
    for(shared_ptr<CNode<triplet>> ptr(matrix.fictionalHead()->getNextNode()); ptr != matrix.fictionalTail() && ptr->getData().lineNum <= lineNum; ptr = ptr->getNextNode())
        if(ptr->getData().lineNum == lineNum && ptr->getData().colNum == colNum)
            return ptr->getData().val;

    return 0;
}

/*
IL FAUT STOCKER _size DANS Matrix2 CAR EN L'ABSENCE D'ÉLÉMENTS NON NULS SUR LA
DERNIÈRE COLONNE OU LA DERNIÈRE LIGNE, IL DEVIENT IMPOSSIBLE DE CONNAITRE
LA TAILLE DE LA MATRICE (QUI EST INDISPENSABLE POUR LES MÉTHODES getVectorAtLine et getVectorAtCol).
*/
