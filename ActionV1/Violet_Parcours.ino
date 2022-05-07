void realisation_parcours_violet(){

    Pince_baissee_max(); 
    Pince_Fermeture_pousse_bloc();
    avancer(260);
    pivoter_g();
    avancer(900);
    reculer(810);
    Pince_Fermeture();
    pivoter_g();
    avancer(670);
    reculer(400);
    pivoter_d();
    avancer(300);
    pivoter_g();
    avancer(380);
    reculer(400);
    pivoter_d();
    avancer(220);
    pivoter_g();

    etape_calibrer_bloc();
    courbure_v3();
    fin_de_match();
}
