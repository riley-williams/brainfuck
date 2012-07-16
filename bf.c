#import "bf.h"

int main (int argc, const char *argv[])
{

  if (argc < 1)
    {
      puts ("no input files");
      return 0;
    }

  FILE *fp = fopen (argv[1], "r");
  long pstack[50];
  long *pstackTop = pstack;
  char c = 0;
  char data[DATA_SIZE];
  initZero (data, DATA_SIZE);
  char *dp = data;
  while ((c = fgetc (fp)) != EOF)
    {
      switch (c)
	{
	case '>':		//increment pointer
	  ++dp;
	  break;
	case '<':		//decrement pointer
	  --dp;
	  break;
	case '+':		//increment data at pointer
	  ++*dp;
	  break;
	case '-':		//decrement data at pointer
	  --*dp;
	  break;
	case '[':		//continue if data at pointer, else jump to next ]
	  if (*dp)
	    {
	      ++pstackTop;
	      *pstackTop = ftell (fp) - 1;
	    }
	  else
	    {
	      while (fgetc (fp) != ']');
	    }
	  break;
	case ']':		//return to corresponding [
	  fseek (fp, *pstackTop, SEEK_SET);
	  --pstackTop;
	  break;
	case '.':		//output byte at pointer
	  putchar (*dp);
	  break;
	case ',':		//store byte input to byte at pointer
	  *dp = getchar ();
	  break;
	default:
	  break;
	}
    }
  fclose (fp);
  return 0;
}
