using UnityEngine;
using System.Collections;
using vsm;

namespace vsm
{
    public static class VSComponentTools
    {
        public static Vector2 toUnityVector2(VSVector2 vsVector)
        {
            return new Vector2(vsVector.x, vsVector.y);
        }

        public static Vector3 toUnityVector3(VSVector3 vsVector)
        {
            return new Vector3(vsVector.x, vsVector.y, vsVector.z);
        }
		
        public static VSVector2 toVSVector2(Vector2 vsVector)
        {
            return new VSVector2(vsVector.x, vsVector.y);
        }

        public static VSVector3 toVSVector3(Vector3 vsVector)
        {
            return new VSVector3(vsVector.x, vsVector.y, vsVector.z);
        }
    }
}
