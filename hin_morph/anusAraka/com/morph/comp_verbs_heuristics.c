#include <string.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

void
comp_verb_heuristics(root,pdgm,comp_verbs)
char root[SUFFWORDSIZE];
char pdgm[WORD_SIZE];
char comp_verbs[20];
{
char suffix_3[4],suffix_4[5],suffix_2[3];
char suffix_5[6],suffix_6[7],suffix_7[8],suffix_8[9],suffix_9[10],suffix_10[11],suffix_11[12];
char tmp[SUFFWORDSIZE];
int len;

comp_verbs[0] = '\0';
len = strlen(root);
if(len>=2) strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");
if(len>=3) strcpy(suffix_3 , root+len-3);else strcpy(suffix_3,"");
if(len>=4) strcpy(suffix_4 , root+len-4);else strcpy(suffix_4,"");
if(len>=5) strcpy(suffix_5 , root+len-5);else strcpy(suffix_5,"");
if(len>=6) strcpy(suffix_6 , root+len-6);else strcpy(suffix_6,"");
if(len>=7) strcpy(suffix_7 , root+len-7);else strcpy(suffix_7,"");
if(len>=8) strcpy(suffix_8 , root+len-8);else strcpy(suffix_8,"");
if(len>=9) strcpy(suffix_9 , root+len-9);else strcpy(suffix_9,"");
if(len>=10) strcpy(suffix_10 , root+len-10);else strcpy(suffix_10,"");
if(len>=11) strcpy(suffix_11 , root+len-11);else strcpy(suffix_11,"");
comp_verbs[0] = '\0';
if((!strcmp(suffix_4,"koVn") || (!strcmp(suffix_2,"ko"))) && !strcmp(pdgm,"kUrco") && ( len > 4 )) {
strcpy(comp_verbs,"koVn");
}
else if((!strcmp(suffix_8,"akavuMdu") || (!strcmp(suffix_6,"akuMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"aka_uMdu");
}
else if((!strcmp(suffix_8,"okavuMdu") || (!strcmp(suffix_6,"okuMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"aka_uMdu");
}
else if((!strcmp(suffix_8,"ekavuMdu") || (!strcmp(suffix_6,"ekuMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"aka_uMdu");
}
else if((!strcmp(suffix_8,"AkavuMdu") || (!strcmp(suffix_6,"AkuMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"aka_uMdu");
}
else if((!strcmp(suffix_5,"akapo") || !strcmp(suffix_5,"ekapo") || !strcmp(suffix_5,"Akapo") || !strcmp(suffix_5,"okapo")) && !strcmp(pdgm,"po")) {
strcpy(comp_verbs,"aka_po");
}
else if((!strcmp(suffix_11,"akuMdAvuMdu") || (!strcmp(suffix_9,"akuMduMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"akuMdA_uMdu");
}
else if((!strcmp(suffix_11,"AkuMdAvuMdu") || (!strcmp(suffix_9,"AkuMduMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"akuMdA_uMdu");
}
else if((!strcmp(suffix_11,"ekuMdAvuMdu") || (!strcmp(suffix_9,"ekuMduMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"akuMdA_uMdu");
}
else if((!strcmp(suffix_11,"okuMdAvuMdu") || (!strcmp(suffix_9,"okuMduMdu"))) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"akuMdA_uMdu");
}
else if(!strcmp(suffix_10,"akuMdAcudu") && !strcmp(pdgm,"cUdu")) {
strcpy(comp_verbs,"akuMdA_cUdu");
}
else if(!strcmp(suffix_10,"AkuMdAcudu") && !strcmp(pdgm,"cUdu")) {
strcpy(comp_verbs,"akuMdA_cUdu");
}
else if(!strcmp(suffix_10,"ekuMdAcudu") && !strcmp(pdgm,"cUdu")) {
strcpy(comp_verbs,"akuMdA_cUdu");
}
else if(!strcmp(suffix_10,"okuMdAcudu") && !strcmp(pdgm,"cUdu")) {
strcpy(comp_verbs,"akuMdA_cUdu");
}
/*
else if((!strcmp(suffix_6,"ivuMdu") || (!strcmp(suffix_4,"uMdu"))) && !strcmp(pdgm,"uMdu") && (len > 8) && (!strcmp(suffix_7,"uMtuMdu"))) {
*/
else if(!strcmp(suffix_3,"ipo") && !strcmp(pdgm,"po")) {
strcpy(comp_verbs,"i_po");
}
else if(!strcmp(suffix_3,"Epo") && !strcmp(pdgm,"po")) {
strcpy(comp_verbs,"i_po");
}
else if(!strcmp(suffix_5,"icUdu") && !strcmp(pdgm,"cUdu")) {
strcpy(comp_verbs,"i_cUdu");
}
else if(!strcmp(suffix_5,"iwIru") && !strcmp(pdgm,"kAlu")) {
strcpy(comp_verbs,"i_wIru");
}
else if(!strcmp(suffix_7,"ipeVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"i_peVttu");
}
else if(!strcmp(suffix_9,"ipAreVyyi") && !strcmp(pdgm,"ceVyyi")) {
strcpy(comp_verbs,"i_pAreVyyi");
}
else if(((!strcmp(suffix_5,"eVyyi")  || !strcmp(suffix_4,"eyyi")) && (len > 6)) && !strcmp(pdgm,"ceVyyi")) {
strcpy(comp_verbs,"i_veVyyi");
}
/* cases for kupo/kuvuMdu/kucUdu/kuwIru/kupeVttu/kupAreVyyi/kuveVyyi :: ku->kuni */
else if((!strcmp(suffix_7,"kuvuMdu")) && !strcmp(pdgm,"uMdu") && (len > 9)){
root[len-7] = '\0';
strcat(root,"kunivuMdu");
strcpy(comp_verbs,"i_uMdu");
}
else if(!strcmp(suffix_4,"kupo") && !strcmp(pdgm,"po")) {
root[len-4] = '\0';
strcat(root,"kunipo");
strcpy(comp_verbs,"i_po");
}
else if(!strcmp(suffix_6,"kucUdu") && !strcmp(pdgm,"cUdu")) {
root[len-6] = '\0';
strcat(root,"kunicUdu");
strcpy(comp_verbs,"i_cUdu");
}
else if(!strcmp(suffix_6,"kuwIru") && !strcmp(pdgm,"kAlu")) {
root[len-6] = '\0';
strcat(root,"kuniwIru");
strcpy(comp_verbs,"i_wIru");
}
else if(!strcmp(suffix_8,"kupeVttu") && !strcmp(pdgm,"peVttu")) {
root[len-8] = '\0';
strcat(root,"kunipeVttu");
strcpy(comp_verbs,"i_peVttu");
}
else if(!strcmp(suffix_10,"kupAreVyyi") && !strcmp(pdgm,"ceVyyi")) {
root[len-10] = '\0';
strcat(root,"kunipAreVyyi");
strcpy(comp_verbs,"i_pAreVyyi");
}
else if((!strcmp(suffix_8,"kuveVyyi") && (len > 7)) && !strcmp(pdgm,"ceVyyi")) {
root[len-8] = '\0';
strcat(root,"kuniveVyyi");
strcpy(comp_verbs,"i_veVyyi");
}
else if(!strcmp(suffix_4,"wUpo") && !strcmp(pdgm,"po")) {
strcpy(comp_verbs,"wU_po");
}
/* This is stopped because of unnecessary answers of wArasapaduwunna,etc
wArasapaduwunna : wArasapadu{v *wU_uMdu_pt_adjl* any } <- unnecessary
wArasapadu{v *np_adjl* any }
else if((!strcmp(suffix_5,"wuMdu")|| !strcmp(suffix_5,"tuMdu")) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"wU_uMdu");
}
*/
/* Following case added by AMBA to handle wUvunnAdu case */
else if((!strcmp(suffix_7,"wUvuMdu") || !strcmp(suffix_7,"tUvuMdu")) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"wU_uMdu");
}
else if((!strcmp(suffix_5,"wUMdu") || !strcmp(suffix_5,"tUMdu")) && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"wU_uMdu");
}
/* These are moved down, in order to apply wU_uMdu rule before i_uMdu  in case of uMdu suffix */
else if((!strcmp(suffix_6,"ivuMdu") || (!strcmp(suffix_4,"uMdu"))) && !strcmp(pdgm,"uMdu") && (len > 8)){
strcpy(comp_verbs,"i_uMdu");
}
else if(!strcmp(suffix_3,"ale") && !strcmp(pdgm,"we")) {
strcpy(comp_verbs,"a_le");
}
else if(!strcmp(suffix_3,"Ale") && !strcmp(pdgm,"we")) {
strcpy(comp_verbs,"a_le");
}
else if(!strcmp(suffix_3,"ele") && !strcmp(pdgm,"we")) {
strcpy(comp_verbs,"a_le");
}
else if(!strcmp(suffix_3,"ole") && !strcmp(pdgm,"we")) {
strcpy(comp_verbs,"a_le");
}
else if(!strcmp(suffix_5,"abadu") && !strcmp(pdgm,"padu")) {
strcpy(comp_verbs,"a_badu");
}
else if(!strcmp(suffix_5,"obadu") && !strcmp(pdgm,"padu")) {
strcpy(comp_verbs,"a_badu");
}
else if(!strcmp(suffix_5,"Abadu") && !strcmp(pdgm,"padu")) {
strcpy(comp_verbs,"a_badu");
}
else if(!strcmp(suffix_5,"ebadu") && !strcmp(pdgm,"padu")) {
strcpy(comp_verbs,"a_badu");
}
else if(!strcmp(suffix_5,"agala") && !strcmp(pdgm,"gala")) {
strcpy(comp_verbs,"a_gala");
}
else if(!strcmp(suffix_5,"Agala") && !strcmp(pdgm,"gala")) {
strcpy(comp_verbs,"a_gala");
}
else if(!strcmp(suffix_5,"ogala") && !strcmp(pdgm,"gala")) {
strcpy(comp_verbs,"a_gala");
}
else if(!strcmp(suffix_5,"egala") && !strcmp(pdgm,"gala")) {
strcpy(comp_verbs,"a_gala");
}
else if((!strcmp(suffix_3,"abo") && !strcmp(pdgm,"po")) || ((!strcmp(suffix_3,"obo") || !strcmp(suffix_3,"Abo") || !strcmp(suffix_3,"ebo")) && !strcmp(pdgm,"po"))){
strcpy(comp_verbs,"a_po");
}
else if(!strcmp(suffix_6,"anivvu") && !strcmp(pdgm,"ivvu")) {
strcpy(comp_verbs,"a_ivvu");
}
else if(!strcmp(suffix_6,"onivvu") && !strcmp(pdgm,"ivvu")) {
strcpy(comp_verbs,"a_ivvu");
}
else if(!strcmp(suffix_6,"Anivvu") && !strcmp(pdgm,"ivvu")) {
strcpy(comp_verbs,"a_ivvu");
}
else if(!strcmp(suffix_6,"enivvu") && !strcmp(pdgm,"ivvu")) {
strcpy(comp_verbs,"a_ivvu");
}
else if(!strcmp(suffix_6,"anuMdu") && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"a_uMdu");
}
else if(!strcmp(suffix_6,"onuMdu") && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"a_uMdu");
}
else if(!strcmp(suffix_6,"AnuMdu") && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"a_uMdu");
}
else if(!strcmp(suffix_6,"enuMdu") && !strcmp(pdgm,"uMdu")) {
strcpy(comp_verbs,"a_uMdu");
}
else if(!strcmp(suffix_5,"amanu") && !strcmp(pdgm,"koVnu")) {
strcpy(comp_verbs,"a_manu");
}
else if((!strcmp(suffix_5,"Amanu")  || !strcmp(suffix_6,"ammanu")) && !strcmp(pdgm,"koVnu")) {
strcpy(comp_verbs,"a_manu");
}
else if((!strcmp(suffix_5,"omanu") || !strcmp(suffix_7,"oVmmanu")) && !strcmp(pdgm,"koVnu")) {
strcpy(comp_verbs,"a_manu");
}
else if((!strcmp(suffix_5,"emanu") || !strcmp(suffix_7,"eVmmanu")) && !strcmp(pdgm,"koVnu")) {
strcpy(comp_verbs,"a_manu");
}
else if(!strcmp(suffix_7,"axalacu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xalacu");
}
else if(!strcmp(suffix_7,"oxalacu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xalacu");
}
else if(!strcmp(suffix_7,"exalacu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xalacu");
}
else if(!strcmp(suffix_7,"Axalacu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xalacu");
}
else if(!strcmp(suffix_7,"agoVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_goVttu");
}
else if(!strcmp(suffix_7,"ogoVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_goVttu");
}
else if(!strcmp(suffix_7,"egoVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_goVttu");
}
else if(!strcmp(suffix_7,"AgoVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_goVttu");
}
else if(!strcmp(suffix_7,"abeVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_beVttu");
}
else if(!strcmp(suffix_7,"ebeVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_beVttu");
}
else if(!strcmp(suffix_7,"AbeVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_beVttu");
}
else if(!strcmp(suffix_7,"obeVttu") && !strcmp(pdgm,"peVttu")) {
strcpy(comp_verbs,"a_beVttu");
}
else if(!strcmp(suffix_5,"axagu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xagu");
}
else if(!strcmp(suffix_5,"oxagu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xagu");
}
else if(!strcmp(suffix_5,"exagu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xagu");
}
else if(!strcmp(suffix_5,"Axagu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_xagu");
}
else if(!strcmp(suffix_6,"axiyyi") && !strcmp(pdgm,"wiyyi")) {
strcpy(comp_verbs,"a_xiyyi");
}
else if(!strcmp(suffix_7,"agalugu") && !strcmp(pdgm,"poVg?du")) {
strcpy(comp_verbs,"a_galugu");
/*
printf("%s\n",pdgm);
printf("%s\n",root);
*/
}
else if(!strcmp(suffix_7,"ogalugu") && !strcmp(pdgm,"poVg?du")) {
strcpy(comp_verbs,"a_galugu");
}
else if(!strcmp(suffix_7,"egalugu") && !strcmp(pdgm,"poVg?du")) {
strcpy(comp_verbs,"a_galugu");
}
else if(!strcmp(suffix_7,"Agalugu") && !strcmp(pdgm,"poVg?du")) {
strcpy(comp_verbs,"a_galugu");
}
else if(!strcmp(suffix_7,"ajoVccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_joVccu");
}
else if(!strcmp(suffix_7,"ojoVccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_joVccu");
}
else if(!strcmp(suffix_7,"ejoVccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_joVccu");
}
else if(!strcmp(suffix_7,"AjoVccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_joVccu");
}
else if(!strcmp(suffix_6,"avaccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_vaccu");
}
else if(!strcmp(suffix_5,"oVccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_vaccu");
}
else if(!strcmp(suffix_6,"Avaccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_vaccu");
}
else if(!strcmp(suffix_6,"ovaccu") && !strcmp(pdgm,"vaccu")) {
strcpy(comp_verbs,"a_vaccu");
}
else if(!strcmp(suffix_5,"ajAlu") && !strcmp(pdgm,"kAlu")) {
strcpy(comp_verbs,"a_jAlu");
}
else if(!strcmp(suffix_5,"ojAlu") && !strcmp(pdgm,"kAlu")) {
strcpy(comp_verbs,"a_jAlu");
}
else if(!strcmp(suffix_5,"ejAlu") && !strcmp(pdgm,"kAlu")) {
strcpy(comp_verbs,"a_jAlu");
}
else if(!strcmp(suffix_5,"AjAlu") && !strcmp(pdgm,"kAlu")) {
strcpy(comp_verbs,"a_jAlu");
}
else if(!strcmp(suffix_7,"aparacu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_paracu");
}
else if(!strcmp(suffix_6,"komanu") && !strcmp(pdgm,"koVnu")) {
strcpy(comp_verbs,"ko_manu");
}
else if(!strcmp(suffix_5,"asAgu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_sAgu");
}
else if(!strcmp(suffix_5,"osAgu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_sAgu");
}
else if(!strcmp(suffix_5,"esAgu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_sAgu");
}
else if(!strcmp(suffix_5,"AsAgu") && !strcmp(pdgm,"pannu")) {
strcpy(comp_verbs,"a_sAgu");
}
else if(!strcmp(suffix_7,"ovalayu") && !strcmp(pdgm,"valayu")) {
strcpy(comp_verbs,"a_valayu");
}
else if(!strcmp(suffix_7,"evalayu") && !strcmp(pdgm,"valayu")) {
strcpy(comp_verbs,"a_valayu");
}
else if(!strcmp(suffix_7,"Avalayu") && !strcmp(pdgm,"valayu")) {
strcpy(comp_verbs,"a_valayu");
}
else if(!strcmp(suffix_6,"valayu") && !strcmp(pdgm,"valayu")) {
if(strcmp(suffix_7,"avalayu")) {
strcpy(tmp,"");
strncpy(tmp,root,len-6);
tmp[len-6] = '\0';
strcat(tmp,"avalayu"),strcpy(root,tmp);
/*
printf("%s\n",root);
*/
}
strcpy(comp_verbs,"a_valayu");
}
}
