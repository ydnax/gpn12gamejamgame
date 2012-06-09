[]()->Level*{
    auto lvl = new Level(nullptr);
    auto n1  = new Node(50,50,lvl);
    n1->unitcount(10);
    n1->Owner(Player::User);
    auto n2 = new Node(400,100,lvl);
    auto n3 = new Node(150,350,lvl);
    auto n4 = new Node(700,250,lvl);
    n3->unitcount(4);
    n3->Owner(Player::Ki);
    n4->unitcount(20);
    n4->Owner(Player::Ki);
    new MoneyInfo(1,1,[=]()->int{return lvl->money();}, lvl);
    
    lvl->setWinFun([=](){
        return  ((n1->unitcount() && n2->unitcount() && n3->unitcount()&& n4->unitcount())&&
            ( (n1->Owner()==Player::User) && (n2->Owner()==Player::User) && (n3->Owner()==Player::User)&& (n4->Owner()==Player::User) ));
    });
    return lvl;
}