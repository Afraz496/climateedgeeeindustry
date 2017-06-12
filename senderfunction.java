public void sender(final String a1,final String a2) {

        final String name,email;


        StringRequest stringRequest = new StringRequest(Request.Method.POST, server_url,
                new Response.Listener<String>() {
                    public void onResponse(String response) {

                    }
                }
                , new Response.ErrorListener() {
            public void onErrorResponse(VolleyError error) {

                Toast.makeText(MainActivity.this,"Error...",Toast.LENGTH_SHORT).show();
                error.printStackTrace();

            }
        }){
            protected Map<String, String> getParams() throws AuthFailureError {
                Map<String,String> params = new HashMap<String, String>(10);

                    params.put("name",a1);
                    params.put("email",a2);

                return params;
            }
        };

        MySingleton.getInstance(MainActivity.this).addTorequestque(stringRequest);
    }
