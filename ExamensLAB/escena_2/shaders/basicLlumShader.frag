#version 330 core

in vec3 fcolor;
out vec4 FragColor;

uniform bool esVaca;		//NOU

uniform bool esX;		//NOU


void main()
{

	if (!esX) FragColor = vec4(fcolor,1);

	else {
		if (esVaca) {
			if (int(gl_FragCoord.y) % 20 > 10) FragColor = vec4(1,1,1,1);
			else FragColor = vec4(0,0,0,1);
		}
		else {
 			if (int(gl_FragCoord.y) % 20 < 10) FragColor = vec4(1,1,1,1);
 			else FragColor = vec4(0,0,0,1);
 		}
	}



}
