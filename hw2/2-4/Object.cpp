#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) { //要考虑水滴飞跃空地的情况！
	// TODO
	switch(size){
		case 1:
			size+=1;
			break;
		case 2:
			size+=1;
			break;
		case 3: //会爆，要考虑上下左右
			size=0;
			splash->score+=1;
			//cout<<1<<endl;
			splash->map[x][y]->set2void(x,y,splash);
			for(int i=y+1;i<splash->size;i++){ //向右
					if(splash->map[x][i]->type==T_WATER){
						splash->map[x][i]->act(fromwhere,fromwho);
						break;
					}
					else if(splash->map[x][i]->type==T_TOXIC){//水碰到毒液了，后面的也都要改！
						if(splash->map[x][i]->size!=1)
							splash->map[x][i]->size-=1;
						else{
							splash->map[x][i]->size-=1;
							splash->map[x][i]->set2void(x,i,splash);
						}
						break;
					}
					else if(splash->map[x][i]->type==T_BARRIER){
						break;
					}
					else continue;
				}
			for(int j=x+1;j<splash->size;j++){  //向下
				if(splash->map[j][y]->type==T_WATER){
					splash->map[j][y]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[j][y]->type==T_TOXIC){
						if(splash->map[j][y]->size!=1)
							splash->map[j][y]->size-=1;
						else{
							splash->map[j][y]->size-=1;
							splash->map[j][y]->set2void(j,y,splash);
						}
						break;
					}
				else if(splash->map[j][y]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			for(int i=y-1;i>=0;i--){  //向左
				if(splash->map[x][i]->type==T_WATER){
					splash->map[x][i]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[x][i]->type==T_TOXIC){
						if(splash->map[x][i]->size!=1)
							splash->map[x][i]->size-=1;
						else{
							splash->map[x][i]->size-=1;
							splash->map[x][i]->set2void(x,i,splash);
						}
						break;
					}
				else if(splash->map[x][i]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			for(int j=x-1;j>=0;j--){  //向上
				if(splash->map[j][y]->type==T_WATER){
					splash->map[j][y]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[j][y]->type==T_TOXIC){
						if(splash->map[j][y]->size!=1)
							splash->map[j][y]->size-=1;
						else{
							splash->map[j][y]->size-=1;
							splash->map[j][y]->set2void(j,y,splash);
						}
						break;
					}
				else if(splash->map[j][y]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			break;
		default:
			break;
	}
	return splash->score;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	// TODO
	cout<<"Error: Cannot act a Void."<<endl;
	return splash->score;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	// TODO
	cout<<"Error: Cannot act a Barrier."<<endl;
	return splash->score;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	// TODO
	switch(size){
		case 1:
			size+=1;
			break;
		case 2:
			size+=1;
			break;
		case 3: //会爆，要考虑上下左右
			splash->score-=1;
			splash->map[x][y]->set2void(x,y,splash);
			for(int i=y+1;i<splash->size;i++){ //向右
					if(splash->map[x][i]->type==T_TOXIC){
						splash->map[x][i]->act(fromwhere,fromwho);
						break;
					}
					else if(splash->map[x][i]->type==T_WATER){//毒液碰到水
						if(splash->map[x][i]->size!=1)
							splash->map[x][i]->size-=1;
						else{
							splash->map[x][i]->size-=1;
							splash->map[x][i]->set2void(x,i,splash);
						}
						break;
					}
					else if(splash->map[x][i]->type==T_BARRIER){
						break;
					}
					else continue;
				}
			for(int j=x+1;j<splash->size;j++){  //向下
				if(splash->map[j][y]->type==T_TOXIC){
					splash->map[j][y]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[j][y]->type==T_WATER){
						if(splash->map[j][y]->size!=1)
							splash->map[j][y]->size-=1;
						else{
							splash->map[j][y]->size-=1;
							splash->map[j][y]->set2void(j,y,splash);
						}
						break;
					}
				else if(splash->map[j][y]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			for(int i=y-1;i>=0;i--){  //向左
				if(splash->map[x][i]->type==T_TOXIC){
					splash->map[x][i]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[x][i]->type==T_WATER){
						if(splash->map[x][i]->size!=1)
							splash->map[x][i]->size-=1;
						else{
							splash->map[x][i]->size-=1;
							splash->map[x][i]->set2void(x,i,splash);
						}
						break;
					}
				else if(splash->map[x][i]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			for(int j=x-1;j>=0;j--){  //向上
				if(splash->map[j][y]->type==T_TOXIC){
					splash->map[j][y]->act(fromwhere,fromwho);
					break;
				}
				else if(splash->map[j][y]->type==T_WATER){
						if(splash->map[j][y]->size!=1)
							splash->map[j][y]->size-=1;
						else{
							splash->map[j][y]->size-=1;
							splash->map[j][y]->set2void(j,y,splash);
						}
						break;
					}
				else if(splash->map[j][y]->type==T_BARRIER){
					break;
				}
				else continue;
			}
			break;
	}
	return splash->score;
}
