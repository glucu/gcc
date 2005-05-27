/* PR tree-optimization/21658
   CCP did not propagate an ADDR_EXPR far enough, preventing the "if"
   statement below from being folded.  */

/* { dg-do compile } */
/* { dg-options "-O2 -fno-tree-dominator-opts -fdump-tree-ccp-details" } */

void link_error (void);

void
f (void)
{
  int a[10];
  int *p = &a[5];
  int *q = p - 1;
  if (q != &a[4])
    link_error ();
}

/* { dg-final { scan-tree-dump-times "with if \\(0\\)" 1 "ccp"} } */
/* { dg-final { cleanup-tree-dump "ccp" } } */
