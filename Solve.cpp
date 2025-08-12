#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>Pieces={{7,19},{23,12},{21,41},{25,28},{5,10},{3,37},{1,46},{14,48},{39,50},{32,16},
{30,43},{34,52},{6,18,38},{8,20,9},{2,11,45},{0,36,47},{24,27,44},{26,29,15},{17,35,51},{42,33,53}};


// S=boxs for each Move
vector<vector<int>>Moves={
    // Changes on R
    {0, 1, 20, 3, 4, 23, 6, 7, 26,          
    15, 12, 9, 16, 13, 10, 17, 14, 11,    
    18, 19, 29, 21, 22, 32, 24, 25, 35,       
    27, 28, 51, 30, 31, 48, 33, 34, 45,
    36, 37, 38, 39, 40, 41, 42, 43, 44,    
    8, 46, 47, 5, 49, 50, 2, 52, 53     
    },
    // Changes on L
    {
    53,1,2,50,4,5,47,7,8,
    9,10,11,12,13,14,15,16,17,
    0,19,20,3,22,23,6,25,26,
    18,28,29,21,31,32,24,34,35,
    42,39,36,43,40,37,44,41,38,
    45,46,33,48,49,30,51,52,27
    },
    // Changes on U
    {
    6,3,0,7,4,1,8,5,2,
    45,46,47,12,13,14,15,16,17,
    9,10,11,21,22,23,24,25,26,
    27,28,29,30,31,32,33,34,35,
    18,19,20,39,40,41,42,43,44,
    36,37,38,48,49,50,51,52,53
    },
    // Changes on D
    {
    0,1,2,3,4,5,6,7,8,
    9,10,11,12,13,14,24,25,26,
    18,19,20,21,22,23,42,43,44,
    33,30,27,34,31,28,35,32,29,
    36,37,38,39,40,41,51,52,53,
    45,46,47,48,49,50,15,16,17,
    },
    // Changes on F
    {
    0,1,2,3,4,5,44,41,38,
    6,10,11,7,13,14,8,16,17,
    24,21,18,25,22,19,26,23,20,
    15,12,9,30,31,32,33,34,35,
    36,37,27,39,40,28,42,43,29,
    45,46,47,48,49,50,51,52,53
    },
    // Changes on B
    {
    11, 14, 17, 3, 4, 5, 6, 7, 8,       
    9, 10, 35, 12, 13, 34, 15, 16, 33,      
    18, 19, 20, 21, 22, 23, 24, 25, 26,    
    27, 28, 29, 30, 31, 32, 36, 39, 42,    
    2, 37, 38, 1, 40, 41, 0, 43, 44,    
    51, 48, 45, 52, 49, 46, 53, 50, 47   
    },
    // Changes on X
    {
    18,19,20,21,22,23,24,25,26,        
    15, 12, 9, 16, 13, 10, 17, 14, 11,    
    27,28,29,30,31,32,33,34,35,     
    53,52,51,50,49,48,47,46,45,
    38, 41, 44, 37, 40, 43, 36, 39, 42,    
    8,7,6,5,4,3,2,1,0  
    },
    // Changes on Y
    {
    6,3,0,7,4,1,8,5,2,
    45,46,47,48,49,50,51,52,53,
    9,10,11,12,13,14,15,16,17,
    29,32,35,28,31,34,27,30,33,
    18,19,20,21,22,23,24,25,26,
    36,37,38,39,40,41,42,43,44,
    }
};

map< char,int >mp;
string cube="",ans="",res="";
bool Is_Cube_Valid=true;
void Append_To_Result(string s){
    res=res+s;
}
bool Check_Is_Cube_Valid(){
    if(ans.size()>500){
        Is_Cube_Valid=false;
    }
    return Is_Cube_Valid;
}
void Performe_Moves(char T){
    if(T!='Y'&&T!='X')ans.push_back(T);
    int x=mp[T];
    string b=cube;
    for(int i=0;i<54;i++){
        cube[i]=b[Moves[x][i]];
    }
}
void Performe_Movess(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='2'){
            Performe_Moves(s[i-1]);
        }
        else if(s[i]=='\''){
            Performe_Moves(s[i-1]);
            Performe_Moves(s[i-1]);
        }else{
            Performe_Moves(s[i]);
        } 
    }
}
bool Check_The_piece(int x,string s){
    string s1="";
    for(auto i:Pieces[x])s1.push_back(cube[i]);
    sort(s1.begin(),s1.end());
    sort(s.begin(),s.end());
    return s==s1;
}
string ReMoves_Duplicates(string s){
    string new_s="";
    s.push_back('=');
    int x=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            if(x%4>0)new_s.push_back(s[i-1]);
            if(x%4>1)new_s.push_back(s[i-1]);
            if(x%4>2)new_s.push_back(s[i-1]);
            x=1;
        }else x++;
    }
    return new_s;
}
void Print_Movess(){
    string s;
    while(1){
        s=ReMoves_Duplicates(ans);
        if(s==ans)break;
        ans=s;
    }
    s="";
    ans.push_back('=');
    int x=1;
    for(int i=1;i<ans.size();i++){
        if(ans[i]!=ans[i-1]){
            if(x%4!=0)s.push_back(ans[i-1]);
            if(x%4==3)s.push_back('\'');
            if(x%4==2)s.push_back('2');
            x=1;
            s.push_back(' ');
        }else x++;
    }
    s.push_back('\n');
    Append_To_Result(s);
    ans="";
}
void sol_edge(string s){
    if(!Check_Is_Cube_Valid())return;
    if(Check_The_piece(1,s)){
        if(cube[23]==s[1]){
            Performe_Movess("F'");
        }else{
            Performe_Movess("U'RU");
        }
        return;
    }
    if(Check_The_piece(2,s)){
        if(cube[21]==s[1]){
            Performe_Movess("F");
        }else{
            Performe_Movess("UL'U'");
        }
        return;
    }
    else if(Check_The_piece(0,s)||Check_The_piece(3,s)){
        Performe_Movess("F");
    }
    else if(Check_The_piece(6,s)){
        Performe_Movess("B");
    }else if(Check_The_piece(11,s)){
        Performe_Movess("D2");
    }
    else if(Check_The_piece(4,s)){
        Performe_Movess("R'");
    }
    else if(Check_The_piece(7,s)){
        Performe_Movess("U'R2U");
    }
    else if(Check_The_piece(9,s)){
        Performe_Movess("D'");
    }
    else if(Check_The_piece(10,s)){
        Performe_Movess("D");
    }
    else if(Check_The_piece(8,s)){
        Performe_Movess("UL2U'");
    }
    else if(Check_The_piece(5,s)){
        Performe_Movess("L");
    }
    else{
        Is_Cube_Valid=false;
        return;
    }
    sol_edge(s);
}
void Solve_White_Cross(){
    sol_edge("wg");
    Print_Movess();
    Append_To_Result("Rotate cube leftward (Red on front)!\n");
    Performe_Movess("Y");
    sol_edge("wr");
    Print_Movess();
    Append_To_Result("Rotate cube leftward (Blue on front)!\n");
    Performe_Movess("Y");
    sol_edge("wb");
    Print_Movess();
    Append_To_Result("Rotate cube leftward (Orange on front)!\n");
    Performe_Movess("Y");
    sol_edge("wo");
    Print_Movess();
    Append_To_Result("Rotate cube leftward (Green on front)!\n");
    Performe_Movess("Y");
}
void Set_F2L_Corner(string s){
    if(Check_The_piece(12,s)){
        Performe_Movess("LDL'");
    }else if(Check_The_piece(13,s)){
        Performe_Movess("R'DR");
    }
    else if(Check_The_piece(14,s)){
        Performe_Movess("B'D'B");
    }
    else if(Check_The_piece(15,s)){
        Performe_Movess("BD2B'");
    }
    else if(Check_The_piece(16,s)){
        Performe_Movess("D");
    }
    else if(Check_The_piece(18,s)){
        Performe_Movess("D'");
    }
    else if(Check_The_piece(19,s)){
        Performe_Movess("D2");
    }
}
void Set_F2L_Edge(string s){
    s.pop_back();
    if(Check_The_piece(1,s)){
        Performe_Movess("D'R'D'RD2");
    }
    else if(Check_The_piece(2,s)){
        Performe_Movess("LDL'D'");
    }
    else if(Check_The_piece(7,s)){
        Performe_Movess("B'D'BD");
    }
    else if(Check_The_piece(8,s)){
        Performe_Movess("BD'B'D");
    }
    else if(Check_The_piece(9,s)){
        Performe_Movess("DR'DRD'");
    }
    else if(Check_The_piece(3,s)){
        Performe_Movess("D'FD'F'D");
    }
}
void sol_F2L(string s){
    string s1=s;
    s1.pop_back();
    Set_F2L_Corner(s);
    Set_F2L_Edge(s);
    if(cube[15]=='w'){
        if(Check_The_piece(11,s1)&&cube[34]!=s[0]){
            Performe_Movess("D'FD2F'D2FD'F'");
        }
        if(Check_The_piece(10,s1)&&cube[30]!=s[0]){
            Performe_Movess("D'FD2F'DFD'F'");
        }
        if(Check_The_piece(10,s1)&&cube[30]==s[0]){
            Performe_Movess("RD'R2'D'R");
        }
        if(Check_The_piece(11,s1)&&cube[34]==s[0]){
            Performe_Movess("R'D'R");
        }
    }else if(cube[26]=='w'){
        if(Check_The_piece(11,s1)&&cube[34]!=s[0]){
            Performe_Movess("D'FDF'DFDF'");
        }
        if(Check_The_piece(10,s1)&&cube[30]!=s[0]){
            Performe_Movess("FDF'");
        }
        if(Check_The_piece(10,s1)&&cube[30]==s[0]){
            Performe_Movess("DR'D2RD2R'DR");
        }
        if(Check_The_piece(11,s1)&&cube[34]==s[0]){
            Performe_Movess("DR'D'RD2R'DR");
        }
    }else{
        if(Check_The_piece(11,s1)&&cube[34]!=s[0]){
            Performe_Movess("D2FDF'DFD'F'");
        }
        if(Check_The_piece(10,s1)&&cube[30]!=s[0]){
            Performe_Movess("DFD2F'DFD'F'");
        }
        if(Check_The_piece(10,s1)&&cube[30]==s[0]){
            Performe_Movess("D2R'D'RD'R'DR");
        }
        if(Check_The_piece(11,s1)&&cube[34]==s[0]){
            Performe_Movess("D'R'D2RD'R'DR");
        }
    }
    Print_Movess();
    Performe_Movess("Y");
}
void Solve_F2L(){
    sol_F2L("grw");
    Append_To_Result("Rotate cube leftward (Red on front)!\n");
    sol_F2L("rbw");
    Append_To_Result("Rotate cube leftward (Blue on front)!\n");
    sol_F2L("bow");
    Append_To_Result("Rotate cube leftward (Orange on front)!\n");
    sol_F2L("ogw");
}
void Solve_OLL_Cross(){
    int y_cnt=0;
    if(cube[1]=='y')y_cnt++;
    if(cube[3]=='y')y_cnt++;
    if(cube[5]=='y')y_cnt++;
    if(cube[7]=='y')y_cnt++;
    if(y_cnt==4)return;
    if(y_cnt==0){
        Performe_Movess("FRUR'U'RUR'U'F'LFUF'U'L'");
    }else{
        while(((cube[3]=='y')+(cube[7]=='y'))==0||(cube[5]=='y')==0){
            Performe_Movess("U");
            if(!Check_Is_Cube_Valid())return;
        }
        if(cube[3]=='y'){
            Performe_Movess("FRUR'U'F'");
        }else{
            Performe_Movess("FRUR'U'F'LFUF'U'L'");
        }
    }
    Print_Movess();
}
void Solve_OLL_Corners(){
    while(cube[2]!='y'){
        Performe_Movess("RD'R'D");
        if(!Check_Is_Cube_Valid())return;
    }
    if(ans.size())Print_Movess();
    if(cube[0]=='y'&&cube[6]=='y'&&cube[8]=='y')return;
    Performe_Movess("U");
    while(cube[2]!='y'){
        Performe_Movess("RD'R'D");
        if(!Check_Is_Cube_Valid())return;
    }
    if(ans.size())Print_Movess();
    if(cube[0]=='y'&&cube[6]=='y')return;
    Performe_Movess("U");
    while(cube[2]!='y'){
        Performe_Movess("RD'R'D");
        if(!Check_Is_Cube_Valid())return;
    }
    if(ans.size())Print_Movess();
    if(cube[0]=='y')return;
    Performe_Movess("U");
    while(cube[2]!='y'){
        Performe_Movess("RD'R'D");
        if(!Check_Is_Cube_Valid())return;
    }
    Print_Movess();
}
void Solve_OLL(){
    Solve_OLL_Cross();
    Solve_OLL_Corners();
}
void Solve_PLL_Corners(){
    int m_cnt=0;
    if(cube[9]==cube[11])m_cnt++;
    if(cube[18]==cube[20])m_cnt++;
    if(cube[36]==cube[38])m_cnt++;
    if(cube[45]==cube[47])m_cnt++;
    if(m_cnt==4)return;
    if(m_cnt==0){
        Performe_Movess("FRU'R'U'RUR'F'RUR'U'R'FRF'");
    }else if(m_cnt==1){
        while(cube[36]!=cube[38]){
            Performe_Movess("U");
            if(!Check_Is_Cube_Valid())return;
        }
        Performe_Movess("RUR'U'R'FR2U'R'U'RUR'F'");
    }
    while(cube[36]!=cube[39]){
        Performe_Movess("U");
        if(!Check_Is_Cube_Valid())return;
    }
    Print_Movess();
}
void Solve_PLL_Mids(){
    if(!Is_Cube_Valid)return;
    int m_cnt=0;
    if(cube[9]==cube[10])m_cnt++;
    if(cube[18]==cube[19])m_cnt++;
    if(cube[36]==cube[37])m_cnt++;
    if(cube[45]==cube[46])m_cnt++;
    if(m_cnt==4){
        while(cube[45]!=cube[48]){
            Performe_Movess("U");
            if(!Check_Is_Cube_Valid())return;
        }
        Print_Movess();
        return;
    }
    if(m_cnt==0){
        Performe_Movess("RU'RURURU'R'U'R2");
    }
    while(cube[45]!=cube[46]){
        Performe_Movess("U");
        if(!Check_Is_Cube_Valid())return;
    }
    Performe_Movess("RU'RURURU'R'U'R2");
    if(cube[18]!=cube[19])Performe_Movess("RU'RURURU'R'U'R2");
    while(cube[45]!=cube[48]){
        Performe_Movess("U");
        if(!Check_Is_Cube_Valid())return;
    }
    Print_Movess();
}
void Solve_PLL(){
    Solve_PLL_Corners();
    Solve_PLL_Mids();
}
int main(){
    mp['R']=0;
    mp['L']=1;
    mp['U']=2;
    mp['D']=3;
    mp['F']=4;
    mp['B']=5;
    mp['X']=6;
    mp['Y']=7;
    freopen("input.txt", "r", stdin);
    for(int i=0;i<54;i++){
        char temp;cin>>temp;
        cube.push_back(temp);
    }
    Append_To_Result("Hold the cube with centers: White on top, Green on front, Red on right!\n");
    Solve_White_Cross();
    Solve_F2L();
    Performe_Movess("X2Y2");
    Append_To_Result("Hold the cube with centers: Yellow on top, Green on front, Orange on right!\n");
    Solve_OLL();
    Solve_PLL();
    Append_To_Result("Cube is Solved!\n");
    if(Check_Is_Cube_Valid()){
        cout<<res<<endl;
    }else{
        cout<<"Give a Valid Input!\n";
    }
}

