#ifndef _COMPONENT_ICE
#define _COMPONENT_ICE

#include <vsm.ice>

module vsm {
	module component {
	
		class VSComponent extends VSObject {
			
		};
		
		class VSTransform extends VSComponent {
			void translate(Vector3 translation);
			void rotate(Vector3 translation);
		}; 
	
	};
};

#endif
