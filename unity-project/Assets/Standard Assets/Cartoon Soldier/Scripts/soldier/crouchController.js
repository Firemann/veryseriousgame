@script RequireComponent(CharacterController);

var crouchSpeedMultiplier : float = 0.5;
var crouchTogglingTime : float = 0.1;
var globalCrouchBlend : float; //0 is standing up, 1 is crouching

private var globalCrouchBlendTarget : float;
private var globalCrouchBlendVelocity : float;
private var disable : boolean;

function Start(){
}

@RPC
function Crouch(){
	if(!disable){
		if (globalCrouchBlend < 0.5){
			globalCrouchBlendTarget = 1.0;
			}
		else{
			globalCrouchBlendTarget = 0.0;
		}
	}
	disable = true;
}

@RPC
function Crouch2(){
	disable = false;
}

function Update () {
	//Crouching.
	if (networkView.isMine){
		if (Input.GetMouseButton(1)){
			networkView.RPC("Crouch", RPCMode.All);
		}
		else{
			networkView.RPC("Crouch2", RPCMode.All);
		}
	}
	globalCrouchBlend = Mathf.SmoothDamp(globalCrouchBlend, globalCrouchBlendTarget, globalCrouchBlendVelocity, crouchTogglingTime);
}