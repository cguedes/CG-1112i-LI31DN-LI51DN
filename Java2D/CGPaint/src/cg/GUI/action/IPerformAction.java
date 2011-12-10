package cg.GUI.action;

import java.awt.Color;
import java.awt.Point;

import cg.GUI.CGPaint;


public interface IPerformAction 
{
	void doAction(CGPaint cg, Point pos, Color color);
	void drawAction(CGPaint cg, Point mousePos, Color color);
}
