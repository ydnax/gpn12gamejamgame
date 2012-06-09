[]()->Level*{
    auto lvl = new Level(nullptr);
    auto n1  = new Node(50,50,lvl);
    n1->unitcount(10);
    n1->Owner(Player::User);
    auto n2 = new Node(400,100,lvl);
    auto n3 = new Node(100,400,lvl);
    n3->unitcount(4);
    new MoneyInfo(1,1,[=]()->int{return lvl->money();}, lvl);
    n3->Owner(Player::Ki);
    lvl->setWinFun([=](){
        return  ((n1->unitcount() && n2->unitcount() && n3->unitcount())&&
            ( (n1->Owner()==Player::User) && (n2->Owner()==Player::User) && (n3->Owner()==Player::User) ));
    });
    return lvl;
}