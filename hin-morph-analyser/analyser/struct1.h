#define SMALL 50
#define MEDIUM 100
struct ans_struct
{
  char root[SMALL];
  int offset;
  char aux_verb[SMALL];
  char pdgm[SMALL];
};
struct wrd_lst
{
  char root[SMALL];
  char cat;
};
struct suff_index
{
  char suff[25];
  int group_no;
  char map[50];
};
struct uword_dict
{
  char sl_word[MEDIUM];
  char tl_word[MEDIUM];
};
struct avy_dict
{
  char sl_rt[100];
  char tl_mng[200];
  char dict[20];
};
