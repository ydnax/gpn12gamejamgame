[]()->Level*{
    auto lvl = new Level(nullptr);
    auto n1  = new Node(50,50,lvl);
    n1->unitcount(10);
    n1->Owner(Player::User);
    auto n2 = new Node(400,100,lvl);
    auto n3 = new Node(100,400,lvl);
    n3->unitcount(4);

    new ImgObj(200, 200, Image("transport $things, make money, transport more things.", 12), lvl);
    new ImgObj(200, 250, Image("select one of your(blue) towns by clicking on it.", 12), lvl);
    new ImgObj(200, 300, Image("send units(u) to other towns by clicking on them", 12), lvl);
    new ImgObj(200, 350, Image("deselect a town by clicking it or pressing space", 12), lvl);
    new ImgObj(200, 400, Image("press b to buy new units for a selected town", 12), lvl);
    new MoneyInfo(1,1,[=]()->int{return lvl->money();}, lvl);
    n3->Owner(Player::Ki);
    lvl->setWinFun([=](){
        return  ((n1->unitcount() && n2->unitcount() && n3->unitcount())&&
            ( (n1->Owner()==Player::User) && (n2->Owner()==Player::User) && (n3->Owner()==Player::User) ));
    });
    return lvl;
}