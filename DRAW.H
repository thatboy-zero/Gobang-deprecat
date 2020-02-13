
void DrawScroll(){
	WORD i,j;
	for(i=0;i<ScrollWidth;i++)
		for(j=0;j<ScrollHeight;j++)
				if(Pscroll[i+j*ScrollWidth].A>0X80)//��͸��
					Pscreen[ScrollX+i+(ScrollY+j)*WinWidth].Color=Pscroll[i+j*ScrollWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(ScrollX,ScrollY,ScrollX+ScrollWidth,ScrollY+ScrollHeight);//ˢ��
}

void DrawCreSrvSign(){
	WORD i,j;
	for(i=0;i<CreSrvWidth;i++)
		for(j=0;j<CreSrvHeight;j++)
				if(Pcresrv[i+j*CreSrvWidth].A>0X80)//��͸��
					Pscreen[CreSrvX+i+(CreSrvY+j)*WinWidth].Color=Pcresrv[i+j*CreSrvWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(CreSrvX,CreSrvY,CreSrvX+CreSrvWidth,CreSrvY+CreSrvHeight);//ˢ��
}
void DrawJoiSrvSign(){
	WORD i,j;
	for(i=0;i<JoiSrvWidth;i++)
		for(j=0;j<JoiSrvHeight;j++)
				if(Pjoisrv[i+j*JoiSrvWidth].A>0X80)//��͸��
					Pscreen[JoiSrvX+i+(JoiSrvY+j)*WinWidth].Color=Pjoisrv[i+j*JoiSrvWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(JoiSrvX,JoiSrvY,JoiSrvX+JoiSrvWidth,JoiSrvY+JoiSrvHeight);//ˢ��
}

void DrawVisualCharacter(BYTE Num){//���黯����
	WORD i,j;
	WORD CX=CharacterX[Num];
	WORD CY=CharacterY[Num];
	WORD CW=CharacterWidth[Num];
	WORD CH=CharacterHeight[Num];
	for(i=0;i<CW;i++)
		for(j=0;j<CH;j++)
			if(Pcharacter[Num][i+j*CW].A>0X80){//��͸��
					Pscreen[CX+i+(CY+j)*WinWidth].R=(Pcharacter[Num][i+j*CW].R+Pmenu[CX+i+(CY+j)*WinWidth].R)>>1;
					Pscreen[CX+i+(CY+j)*WinWidth].G=(Pcharacter[Num][i+j*CW].G+Pmenu[CX+i+(CY+j)*WinWidth].G)>>1;
					Pscreen[CX+i+(CY+j)*WinWidth].B=(Pcharacter[Num][i+j*CW].B+Pmenu[CX+i+(CY+j)*WinWidth].B)>>1;
			}
	if(AutoFlushBatchDraw)
		FlushBatchDraw(CX,CY,CX+CW,CY+CH);//ˢ��
}
void DrawCharacter(BYTE Num){//������
	WORD i,j;
	WORD CX=CharacterX[Num];
	WORD CY=CharacterY[Num];
	WORD CW=CharacterWidth[Num];
	WORD CH=CharacterHeight[Num];
	for(i=0;i<CW;i++)
		for(j=0;j<CH;j++)
				if(Pcharacter[Num][i+j*CW].A>0X80)//��͸��
					Pscreen[CX+i+(CY+j)*WinWidth].Color=Pcharacter[Num][i+j*CW].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(CX,CY,CX+CW,CY+CH);//ˢ��
}
void DrawClose(){
	WORD i,j;
	for(i=0;i<CloseWidth;i++)
		for(j=0;j<CloseHeight;j++)
				if(Pclose[i+j*CloseWidth].A>0X80)//��͸��
					Pscreen[CloseX+i+(CloseY+j)*WinWidth].Color=Pclose[i+j*CloseWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(CloseX,CloseY,CloseX+CloseWidth,CloseY+CloseHeight);//ˢ��
}
void DrawClose(WORD X,WORD Y){//ָ��λ��
	WORD i,j;
	for(i=0;i<CloseWidth;i++)
		for(j=0;j<CloseHeight;j++)
				if(Pclose[i+j*CloseWidth].A>0X80)//��͸��
					Pscreen[X+i+(Y+j)*WinWidth].Color=Pclose[i+j*CloseWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(X,Y,X+CloseWidth,Y+CloseHeight);//ˢ��
}

void DrawMenu(){
	WORD i,j;
	for(i=0;i<MenuWidth;i++)
		for(j=0;j<MenuHeight;j++)
			Pscreen[i+j*WinWidth].Color=Pmenu[i+j*MenuWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(0,0,MenuWidth,MenuHeight);//ˢ��
}



void DrawGameStart(bool Sign){
	WORD i,j;
	for(i=0;i<GameStartWidth;i++)
		for(j=0;j<GameStartHeight;j++)
				if(Pgame[Sign][i+j*GameStartWidth].A>0X80)//��͸��
					Pscreen[GameStartX+i+(GameStartY+j)*WinWidth].Color=Pgame[Sign][i+j*GameStartWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(GameStartX,GameStartY,GameStartX+GameStartWidth,GameStartY+GameStartHeight);//ˢ��
}
void DrawPiece(BYTE x,BYTE y){	//��������
	WORD SrcX=DB_X+x*PieceSize;	//���
	WORD SrcY=DB_Y+y*PieceSize;	//���
	WORD i,j;					//����ָ��

	if(!Map[x][y])//������
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
	else if(Map[x][y]==ValueBlack)
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				if(Pblack[i+j*PieceSize].A<0X80)//͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
				else							//��͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pblack[i+j*PieceSize].Color;
	else if(Map[x][y]==ValueWhite)
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				if(Pwhite[i+j*PieceSize].A<0X80)//͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
				else							//��͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pwhite[i+j*PieceSize].Color;
				
	if(AutoFlushBatchDraw)
		FlushBatchDraw(SrcX,SrcY,SrcX+PieceSize,SrcY+PieceSize);//ˢ��
}
void DrawCard(){//����Ƭ
	WORD i,j;
	for(i=0;i<CardWidth;i++)
		for(j=0;j<CardHeight;j++)
				if(Pcard[i+j*CardWidth].A>0X80)//��͸��
					Pscreen[CardX+i+(CardY+j)*WinWidth].Color=Pcard[i+j*CardWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(CardX,CardY,CardX+CardWidth,CardX+CardHeight);//ˢ��
}
void DrawMusicNote(){//������
	WORD i,j;
	for(i=0;i<MusicWidth;i++)
		for(j=0;j<MusicHeight;j++)
				if(Pmusic[i+j*MusicWidth].A>0X80)//��͸��
					Pscreen[MusicX+i+(MusicY+j)*WinWidth].Color=Pmusic[i+j*MusicWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(MusicX,MusicY,MusicX+MusicWidth,MusicY+MusicHeight);//ˢ��
}
void DrawSwitch(){//������
	WORD i,j;
	for(i=0;i<SwitchWidth;i++)
		for(j=0;j<SwitchHeight;j++)
				if(Pswitch[SwitchState][i+j*SwitchWidth].A>0X80)//��͸��
					Pscreen[SwitchX+i+(SwitchY+j)*WinWidth].Color=Pswitch[SwitchState][i+j*SwitchWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(SwitchX,SwitchY,SwitchX+SwitchWidth,SwitchY+SwitchHeight);//ˢ��
}
void DrawBackGround(){
	WORD i,j;
	for(i=0;i<BackWidth;i++)
		for(j=0;j<BackHeight;j++)
			Pscreen[BackX+i+(BackY+j)*WinWidth].Color=Pback[i+j*BackWidth].Color;
		if(AutoFlushBatchDraw)
			FlushBatchDraw(BackX,BackY,BackX+BackWidth,BackY+BackHeight);//ˢ��

}
void DrawSign(){
	WORD i,j;
	for(i=0;i<SignWidth;i++)
		for(j=0;j<SignHeight;j++)
				if(Psign[i+j*SignWidth].A>0X80)//��͸��
					Pscreen[SignX+i+(SignY+j)*WinWidth].Color=Psign[i+j*SignWidth].Color;
	if(AutoFlushBatchDraw)
		FlushBatchDraw(SignX,SignY,SignX+SignWidth,SignY+SignHeight);//ˢ��
}
void DrawVisualPiece(BYTE x,BYTE y,BYTE piece){	//������������
	WORD SrcX=DB_X+x*PieceSize;	//���
	WORD SrcY=DB_Y+y*PieceSize;	//���
	WORD i,j;					//����ָ��

	if(!piece)//������
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
	else if(piece==ValueBlack)
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				if(Pblack[i+j*PieceSize].A<0X80)//͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
				else{							//��͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].R=(Pboard[SrcX+i+(SrcY+j)*MapWidth].R+Pblack[i+j*PieceSize].R)>>1;
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].G=(Pboard[SrcX+i+(SrcY+j)*MapWidth].G+Pblack[i+j*PieceSize].G)>>1;
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].B=(Pboard[SrcX+i+(SrcY+j)*MapWidth].B+Pblack[i+j*PieceSize].B)>>1;
				}
	else if(piece==ValueWhite)
		for(i=0;i<PieceSize;i++)
			for(j=0;j<PieceSize;j++)
				if(Pwhite[i+j*PieceSize].A<0X80)//͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].Color=Pboard[SrcX+i+(SrcY+j)*MapWidth].Color;
				else{							//��͸��
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].R=(Pboard[SrcX+i+(SrcY+j)*MapWidth].R+Pwhite[i+j*PieceSize].R)>>1;
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].G=(Pboard[SrcX+i+(SrcY+j)*MapWidth].G+Pwhite[i+j*PieceSize].G)>>1;
					Pscreen[SrcX+i+(SrcY+j)*WinWidth].B=(Pboard[SrcX+i+(SrcY+j)*MapWidth].B+Pwhite[i+j*PieceSize].B)>>1;
				}
	if(AutoFlushBatchDraw)
		FlushBatchDraw(SrcX,SrcY,SrcX+PieceSize,SrcY+PieceSize);//ˢ��
}
void DrawWholeBoard(){
	putimage(0,0,&Board);//��������
	for(BYTE i=0;i<MAP_X;i++)
		for(BYTE j=0;j<MAP_Y;j++)
			DrawPiece(i,j);
	if(AutoFlushBatchDraw)
		FlushBatchDraw();//ˢ��

}
void DrawWholeWnd(){
	DrawWholeBoard();//������������
	DrawBackGround();//���Ʊ���
	DrawSign();//���Ʊ�ʶ��
	DrawSwitch();//���ƿ���
	DrawClose();//���ƹرհ�ť
	if(SwitchState)
		DrawMusicNote();//��������
	else
		DrawCard();//������Ƭ
	if(AutoFlushBatchDraw)
		FlushBatchDraw();//ˢ��
}
void DrawStartBG(){
	putimage(0,0,&StartBG);
	if(AutoFlushBatchDraw)
		FlushBatchDraw();//ˢ��
}