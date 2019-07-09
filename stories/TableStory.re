let str = React.string;

Storybook.(
  storiesOf("Table", module_)
  |> add("default", () =>
       <Table
         headers=[|"Name", "Email", "Phone"|]
         data=[|
           {
             "name": "Yuri",
             "email": "yuri@email.com",
             "phone": "(47) 9 9999-9999",
           },
           {
             "name": "Guilherme",
             "email": "guilherme@email.com",
             "phone": "(11) 9 9999-9999",
           },
           {
             "name": "Gabriel",
             "email": "gabriel@email.com",
             "phone": "(11) 9 9999-9999",
           },
           {
             "name": "George",
             "email": "george@email.com",
             "phone": "(11) 9 9999-9999",
           },
           {
             "name": "Eliabe",
             "email": "eliabe@email.com",
             "phone": "(11) 9 9999-9999",
           },
           {
             "name": "Medson",
             "email": "medson@email.com",
             "phone": "(11) 9 9999-9999",
           },
           {
             "name": "Jefferson",
             "email": "jefferson@email.com",
             "phone": "(11) 9 9999-9999",
           },
         |]
         renderRow={row =>
           <TableRow
             key={
               row##email;
             }>
             <TableCell> {str(row##name)} </TableCell>
             <TableCell> {str(row##email)} </TableCell>
             <TableCell> {str(row##phone)} </TableCell>
           </TableRow>
         }
       />
     )
  |> add("Empty", () =>
       <Table
         headers=[|"Name", "Email", "Phone"|]
         data=[||]
         renderRow={row =>
           <TableRow
             key={
               row##email;
             }>
             <TableCell> {str(row##name)} </TableCell>
             <TableCell> {str(row##email)} </TableCell>
             <TableCell> {str(row##phone)} </TableCell>
           </TableRow>
         }
       />
     )
  |> add("Loading", () =>
       <Table
         headers=[|"Name", "Email", "Phone"|]
         data=[||]
         loading=true
         renderRow={row =>
           <TableRow
             key={
               row##email;
             }>
             <TableCell> {str(row##name)} </TableCell>
             <TableCell> {str(row##email)} </TableCell>
             <TableCell> {str(row##phone)} </TableCell>
           </TableRow>
         }
       />
     )
);
