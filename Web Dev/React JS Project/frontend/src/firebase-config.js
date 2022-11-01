import { initializeApp } from "firebase/app";
import { getAuth } from 'firebase/auth'
import { getFirestore } from "firebase/firestore";

const firebaseConfig = {
    apiKey: "AIzaSyCn0ZwrkyytMvOp3eU0otnXov2I_bWIGpI",
    authDomain: "salud-os.firebaseapp.com",
    projectId: "salud-os",
    storageBucket: "salud-os.appspot.com",
    messagingSenderId: "215300274299",
    appId: "1:215300274299:web:80a57c774a58d50a234ade"

    // apiKey: "AIzaSyDmeb2gZdvdXrEpX1S3_IowQRdu1XLPhmY",
    // authDomain: "salud-os-prueba.firebaseapp.com",
    // projectId: "salud-os-prueba",
    // storageBucket: "salud-os-prueba.appspot.com",
    // messagingSenderId: "99758758179",
    // appId: "1:99758758179:web:e6b920b517ff131a2b1496"
};

const app = initializeApp(firebaseConfig);
export const db = getFirestore(app);

export const auth = getAuth()
