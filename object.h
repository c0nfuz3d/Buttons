#include "point.h"
#include "color.h"
class object
{


    public:
    char* name;
    int number;
    int category;
    point2f current;
    point2f resting;//resting point
    int x,y;

    double rotation;
    int width, height;
    color current_color;//RGB values
    color prev_color;
    bool visible;

    int xmax,xmin,ymax,ymin;

    void set_boundaries()
    {
        xmin= current.x-(width/2);
        xmax= current.x+(width/2);
        ymin= current.y-(height/2);
        ymax= current.y+(height/2);

    }

       /*     void render()
    {

        glPushMatrix();//need push and pop so that entire scene isn't rotated
        glTranslatef(current.x,current.y,0.0);//translate object according to coordinates
        glRotatef(rotation,0,0,1);//rotates object with object.rotation
        glTranslatef(-current.x,-current.y,0.0);//translate object according to coordinates
        glColor3f(current_color.r,current_color.g,current_color.b);//color the square with object.current_color

        if(!visible)
        {
            printf("object %d: %s rendered\n", number, name);
            visible=true;
        }
        glBegin(GL_POLYGON);//draws a filled in rectangle
        glVertex2f(xmin, ymin); // The bottom left corner
        glVertex2f(xmin, ymax); // The top left corner
        glVertex2f(xmax, ymax); // The top right corner
        glVertex2f(xmax, ymin); // The bottom right corner

        glEnd();//finish drawing

        glPopMatrix();//reset transformation matrix

    }*/

    void undo_color()
    {
        current_color.r=prev_color.r;
        current_color.g=prev_color.g;
        current_color.b=prev_color.b;
    }

    int within_radius;

    void rotate(double angle)
    {
        rotation+=angle;
    }

    int getRadius()
    {
        return (width+height)/8;
    }


    object()//constructs an object
    {
        name="generic object";
        current.x=320;
        current.y=160;
        resting.x=320;
        resting.y=160;
        width=64;
        height=64;
        current_color.set(0.0,0.0,0.0);
        prev_color.set(current_color.r,current_color.g,current_color.b);
        rotation=90;
        visible=false;
        printf("object %d: %s created\n", number, name);
    }

    object(float x, float y, float w, float h, color c)
    {
        current.x=x;
        current.y=y;
        width=w;
        height=h;
        current_color=c;
        rotation=90;
        visible=false;
    }

    ~object()
    {
        printf("object %d: %s distroyed\n", number, name);
    }

};
