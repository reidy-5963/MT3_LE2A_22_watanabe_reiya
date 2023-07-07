#include <math.h>
#include "DxLib.h"

//* マクロ定義 *///////////////////////////////////////////////////////////////////////////

#define		CAMERA_L		170.0f		//カメラの初めの高さ(170.0cm)
#define		CAMERA_SPEED	10.0		
#define		CAMERA_NEAR		10.0		
#define		CAMERA_FAR		1000.0		
#define		CAMERA_FOV		50.0		//カメラの最高視野角

//* 構造体定義 *///////////////////////////////////////////////////////////////////////////

typedef struct{
	int Handle;
	float Pos_X, Pos_Y, Pos_Z;
	float Rot_X, Rot_Y, Rot_Z;
}Model_t;

typedef	struct{
	float Pos_X, Pos_Y, Pos_Z;
	float Rot_V, Rot_H, Rot_T;
	float Fov, Move;
}Camera_t;

//* 変数宣言 */////////////////////////////////////////////////////////////////////////////

Model_t Model;
Camera_t Camera;

int Key[256];

//* プロトタイプ宣言 *////////////////////////////////////////////////////////////////////

int GetHitKeyStateAll_2();		//キー入力のやつ
int ChangeWindowMessageBox();	//ウィンドウ切替のやつ

float rad( float );                        //ラジアンに変換するやつ

void Model_Init( int, float, float, float, float, float, float );		//モデルを設定するやつ
void Camera_Init( float, float, float, float, float, float, float );	//カメラを設定するやつ

//* main */////////////////////////////////////////////////////////////////////////////////

int WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int ){
	ChangeWindowMessageBox(), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK );
	SetDrawMode( DX_DRAWMODE_BILINEAR );

	//カメラとモデルの初期設定
	Camera_Init( 400.0f, CAMERA_L/2, 0.0f, 0.0f, 0.0f, 0.0f, CAMERA_FOV );
	Model_Init( MV1LoadModel("Model/Field.mqo"), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f );

	while( !ScreenFlip() && !ProcessMessage() && !ClearDrawScreen() 
									&& !GetHitKeyStateAll_2() && !Key[KEY_INPUT_ESCAPE] ){
	
                //カメラの設置
		SetCameraNearFar( CAMERA_NEAR, CAMERA_FAR );
		SetupCamera_Perspective( rad( Camera.Fov ) );
		SetCameraPositionAndAngle( VGet( Camera.Pos_X, Camera.Pos_Y, Camera.Pos_Z ),
									rad( Camera.Rot_V ), rad( Camera.Rot_H ), rad( Camera.Rot_T ) );

                //カメラの動きを制御
		Camera.Move = 0.0f;

                //前進、後退
		if	   ( Key[KEY_INPUT_UP] > 0 )		Camera.Move =  CAMERA_SPEED;
		else if( Key[KEY_INPUT_DOWN] > 0 )		Camera.Move = -CAMERA_SPEED;

                //旋回
		if	   ( Key[KEY_INPUT_LEFT] > 0 )		Camera.Rot_H -= 2.0f;
		else if( Key[KEY_INPUT_RIGHT] > 0 )		Camera.Rot_H += 2.0f;

		//カメラの座標を計算
		Camera.Pos_X += Camera.Move * sin( rad( Camera.Rot_H ) );
		Camera.Pos_Z += Camera.Move * cos( rad( Camera.Rot_H ) );

                //モデルを設置
		MV1SetPosition( Model.Handle, VGet( Model.Pos_X, Model.Pos_Y, Model.Pos_Z ) );
		MV1SetRotationXYZ( Model.Handle, VGet( rad( Model.Rot_X ), rad( Model.Rot_Y ), rad( Model.Rot_Z ) ) );
		MV1DrawModel( Model.Handle );
	}

	DxLib_End();
	return 0;
}

//* 自作関数 *//////////////////////////////////////////////////////////////////////////////////////////////

int GetHitKeyStateAll_2(){
	char KeyBuf[256];
	GetHitKeyStateAll( KeyBuf );

	for( int i=0; i<256; i++ ){
		if( KeyBuf[i] != 0 )	Key[i]++;
		else					Key[i]=0;
	}

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ChangeWindowMessageBox(){
	int Flag = MessageBox( NULL,
						   TEXT( "フルスクリーンで表示しますか？" ),
						   TEXT( "スクリーン設定" ),
						   MB_YESNO | MB_ICONQUESTION );

	if( Flag == IDNO )
		if( ChangeWindowMode( TRUE ) != 0 )
			return -1;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

float rad( float angle ){
	return angle * PHI_F/180.0f;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Model_Init( int Handle, float Px, float Py, float Pz, float Rx, float Ry, float Rz ){

	Model.Handle = Handle;
	Model.Pos_X  = Px;
	Model.Pos_Y  = Py;
	Model.Pos_Z  = Pz;
	Model.Rot_X  = Rx;
	Model.Rot_Y  = Ry;
	Model.Rot_Z  = Rz;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Camera_Init( float Px, float Py, float Pz, float Rv, float Rh, float Rt, float F ){

	Camera.Pos_X = Px;
	Camera.Pos_Y = Py;
	Camera.Pos_Z = Pz;
	Camera.Rot_V = Rv;
	Camera.Rot_H = Rh;
	Camera.Rot_T = Rt;
	Camera.Fov   = F;

}