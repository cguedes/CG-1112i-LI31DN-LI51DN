package cg.algorithms.line;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.IRasterDevice;

public class MidPointLineAlgorithm implements IScanLineAlgorithm {

	public void drawLine(IRasterDevice dc, Point start, Point end) {
		drawLine(dc, start, end, Color.BLACK);

	}

	public void drawLine(IRasterDevice dc, Point start, Point end, Color color) 
	{
		int dx=end.x-start.x;
		int dy=end.y-start.y;
		int d=2*dy-dx;
		int incrE=2*dx;
		int incrNE=2*(dy-dx);
		int x=start.x, y=start.y;
		
		dc.writePixel(x, y, color);
		while(x<end.x)
		{
			
			if(d<=0) //escolhe-se E
				d+=incrE;
			else
			{
				d+=incrNE;
				++y;
			}
			++x;
			dc.writePixel(x, y, color);
		}
		                  
		 
	}

}
