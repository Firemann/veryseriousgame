using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace vsm.unity
{

    class VSSoldierI : VSSoldier
    {
		public const int MVT_VALUE = 5;
        private GameObject soldierInst;
		private soldierMovement soldierMvt;

        public VSSoldierI()
        {
			Loom.RunAsync(()=>{
				Loom.QueueOnMainThread(()=>{
				
					GameObject[] spawners = GameObject.FindGameObjectsWithTag("Respawn") as GameObject[];
				
		            int rand = UnityEngine.Random.Range(0, spawners.Length);
		            GameObject spawn = spawners[rand];
					GameObject soldier = Resources.Load("soldier") as GameObject;
		            soldierInst = Network.Instantiate(soldier, spawn.transform.position, Quaternion.identity, 0) as GameObject;
		            soldierMvt = soldierInst.GetComponent<soldierMovement>();
				});
	        });
        }

        public override void move(VSDirection direction, Ice.Current current__)
        {
			switch(direction) {
			case VSDirection.DOWN:
				soldierMvt.Move(0, -MVT_VALUE);
				break;
			case VSDirection.LEFT:
				soldierMvt.Move(-MVT_VALUE, 0);
				break;
			case VSDirection.RIGHT:
				soldierMvt.Move(MVT_VALUE, 0);
				break;
			case VSDirection.UP:
				soldierMvt.Move(0, MVT_VALUE);
				break;
			}
        }

        public override void run(bool isRunning, Ice.Current current__)
        {
            throw new NotImplementedException();
        }

        public override void crounch(Ice.Current current__)
        {
            throw new NotImplementedException();
        }
		
		public override VSVector3 getPosition(Ice.Current current__)
		{
			return VSComponentTools.toVSVector3(soldierInst.transform.position);
		}
    }

}
