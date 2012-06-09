[]()->Level*{
    auto lvl = new Level(nullptr);
    auto n1  = new Node(50,50,lvl);
    n1->unitcount(10);
    n1->Owner(Player::User);
    auto n2 = new Node(400,100,lvl);
    auto n3 = new Node(100,400,lvl);
    n3->unitcount(4);

    new ImgObj(100, 200, Image("Click a town to select it, click it again or press space to deselect.", 12), lvl);
    new ImgObj(150, 250, Image("After selecting one of your towns, click another one to send a robot.", 12), lvl);
    new ImgObj(200, 300, Image("To win a level if you hold all towns.", 12), lvl);
    n3->Owner(Player::Ki);
    lvl->setWinFun([=](){
        return  ((n1->unitcount() && n2->unitcount() && n3->unitcount())&&
            ( (n1->Owner()==Player::User) && (n2->Owner()==Player::User) && (n3->Owner()==Player::User) ));
}